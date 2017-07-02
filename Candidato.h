#ifndef URNA_CANDIDATO_H
#define URNA_CANDIDATO_H

#include <iostream>

using namespace std;

class Candidato {

public:
    string cargo;
    string nome;
    int votos;

    Candidato(string cargo, string nome, int votos);
};


#endif //URNA_CANDIDATO_H
