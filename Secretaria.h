#ifndef URNA_SECRETARIA_H
#define URNA_SECRETARIA_H

#include <iostream>
#include <vector>
#include "Candidato.h"

using namespace std;

class Secretaria {

public:
    string nome;
    vector<Candidato> candidatos;

    Secretaria(string nome);
};


#endif //URNA_SECRETARIA_H
