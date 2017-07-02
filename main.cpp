#include <iostream>
#include <fstream>
#include <regex>
#include "Sessao.h"
#include "Arquivo.h"

using namespace std;

int main(int argc, char* argv[]) {

    cout << "count: " << argc << endl;


    string path = "../data/sessao_fp123.txt";
    Sessao sessao = Arquivo::carregarArquivo(path);

    cout << "sessao: " << sessao.nome << endl;

    for (Secretaria s : sessao.secretarias) {
        cout << "\tsecretaria: " << s.nome << endl;
        for (Candidato c : s.candidatos) {
            cout << "\t\tcandidato: " << c.cargo << " - " << c.nome << " - " << c.votos << endl;
        }
    }

    exit(EXIT_SUCCESS);
}
