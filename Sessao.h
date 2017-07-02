#ifndef URNA_SESSAO_H
#define URNA_SESSAO_H

#include <iostream>
#include <list>
#include <vector>
#include "Secretaria.h"

using namespace std;

class Sessao {

public:
    string nome;
    vector<Secretaria> secretarias;

    Sessao();
    Sessao(string nome);
    friend ostream& operator <<(ostream &os, Sessao &s);

    void adicionaSecretaria(Secretaria secretaria);
};

#endif //URNA_SESSAO_H
