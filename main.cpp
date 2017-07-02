#include <iostream>
#include <fstream>
#include <regex>
#include "Sessao.h"
#include "Arquivo.h"

using namespace std;

void grava() {

    vector<Candidato> candidatos;
    candidatos.push_back(*new Candidato("Faxineiro", "Edvaldo", 0));

    Secretaria secretaria("OutroTeste");
    secretaria.candidatos = candidatos;
    vector<Secretaria> secretarias;
    secretarias.push_back(secretaria);

    Sessao sessao("teste");
    sessao.secretarias = secretarias;

    Arquivo::gravarSessao(sessao);
}

Sessao carrega(string nomeSessao) {
    string path = "../data/sessao_" + nomeSessao + ".txt";
    Sessao sessao = Arquivo::carregarArquivo(path);

    cout << "Sessao: " << sessao.nome << endl;
    return sessao;

    //sessao.nome = "teste1";
    //Arquivo::gravarSessao(sessao);

    //for (Secretaria s : sessao.secretarias) {
    //    cout << "\tsecretaria: " << s.nome << endl;
    //    for (Candidato c : s.candidatos) {
    //        cout << "\t\tcandidato: " << c.cargo << " - " << c.nome << " - " << c.votos << endl;
    //    }
    //}

    //exit(EXIT_SUCCESS);
}

void mostra(string nomeSessao) {
    string path = "../data/sessao_" + nomeSessao + ".txt";
    Sessao sessao = Arquivo::carregarArquivo(path);

    system("cls");
    cout << "Sessao: " << sessao.nome << endl;

    for (Secretaria s : sessao.secretarias) {
        cout << "\tsecretaria: " << s.nome << endl;
        for (Candidato c : s.candidatos) {
            cout << "\t\tcandidato: " << c.cargo << " - " << c.nome << " - " << c.votos << endl;
        }
    }
}

void vota(Sessao sessao, string nomeCandidato) {
    for (Secretaria &s : sessao.secretarias) {
        for (Candidato &c : s.candidatos) {
            if (c.nome.compare(nomeCandidato) == 0) {
                c.votos++;
                cout << "Voto adicionado ao candidato \"" << c.nome << "\" da secretaria \"" << s.nome << "\"" << endl;

                Arquivo::gravarSessao(sessao);
                return;
            }
        }
    }

    cout << "Nenhum candidado encontrado com o nome \"" << nomeCandidato << "\"" << endl;
}

int main(int argc, char* argv[]) {
    //cout << "count: " << argc << endl;

    string flag(argv[1]);
    if (flag.compare("sessao") == 0) {
        Sessao sessao = carrega(argv[2]);

        string command(argv[3]);
        if (command.compare("votar") == 0) {
            vota(sessao, argv[4]);

        } else if (command.compare("mostrar") == 0) {
            mostra(argv[2]);
        }
    }

    //grava();
    //carrega("fp123");
}
