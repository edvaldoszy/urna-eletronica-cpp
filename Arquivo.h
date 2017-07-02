#ifndef URNA_ARQUIVO_H
#define URNA_ARQUIVO_H

#include <iostream>
#include <fstream>
#include "Sessao.h"

using namespace std;

class Arquivo {

public:
    Arquivo();
    static string line(ifstream &ifs);
    static Sessao carregarArquivo(string path);


protected:
    static Sessao carregaSessao(ifstream &ifs);
    static Secretaria carregaSecretaria(ifstream &ifs);
    static vector<Candidato> carregaCandidatos(ifstream &ifs);

};


#endif //URNA_ARQUIVO_H
