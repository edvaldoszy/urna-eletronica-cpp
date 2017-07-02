#ifndef URNA_ARQUIVO_H
#define URNA_ARQUIVO_H

#include <iostream>
#include <fstream>
#include "Sessao.h"

using namespace std;

class Arquivo {

public:
    Arquivo();
    static void gravarSessao(Sessao sessao);
    static Sessao carregarArquivo(string path);

protected:
    static string line(ifstream &ifs);

    static void gravaSecretarias(ofstream &ofs, vector<Secretaria> secretarias);
    static void gravaCandidatos(ofstream &ofs, vector<Candidato> candidatos);

    static Sessao carregaSessao(ifstream &ifs);
    static Secretaria carregaSecretaria(ifstream &ifs);
    static vector<Candidato> carregaCandidatos(ifstream &ifs);

};


#endif //URNA_ARQUIVO_H
