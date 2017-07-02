#include "Secretaria.h"

Secretaria::Secretaria(string nome) {
    this->nome = nome;
}

void Secretaria::setCandidatos(vector<Candidato> candidatos) {
    this->candidatos = candidatos;
}
