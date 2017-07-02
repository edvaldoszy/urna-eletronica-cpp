#include <iostream>
#include <regex>
#include "Sessao.h"
#include "Arquivo.h"

using namespace std;

void criaSessao(string nomeSessao) {
    Sessao sessao(nomeSessao);
    Arquivo::gravarSessao(sessao);
    cout << "Sessao \"" + sessao.nome << "\" criada com sucesso" << endl;
}

void criaSecretaria(Sessao sessao) {
    cout << "Nome da secretaria: ";
    string nomeSecretaria;
    cin >> nomeSecretaria;

    Secretaria secretaria(nomeSecretaria);

    string nomeCandidato;
    cout << "Nome do candidato (0 para sair): ";
    cin >> nomeCandidato;

    while (nomeCandidato.compare("0") != 0) {
        cout << "Nome o cargo do candidato: ";
        string cargoCandidato;
        cin >> cargoCandidato;

        Candidato candidato = (* new Candidato(cargoCandidato, nomeCandidato, 0));
        secretaria.candidatos.push_back(candidato);

        cout << "Nome do candidato (0 para sair): ";
        cin >> nomeCandidato;
    }

    sessao.secretarias.push_back(secretaria);
    Arquivo::gravarSessao(sessao);
    cout << "Secretaria criada com sucesso" << endl;
}

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

    string flag(argv[1]);
    if (flag.compare("sessao") == 0) {

        string command(argv[3]);
        if (command.compare("criar") == 0) {
            criaSessao(argv[2]);
            return EXIT_SUCCESS;
        }

        Sessao sessao = carrega(argv[2]);
        if (command.compare("criarSecretaria") == 0) {
            criaSecretaria(sessao);

        } else if (command.compare("votar") == 0) {
            vota(sessao, argv[4]);

        } else if (command.compare("mostrar") == 0) {
            mostra(argv[2]);
        }
    }
}
