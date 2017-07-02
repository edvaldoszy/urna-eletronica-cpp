#include "Sessao.h"

Sessao::Sessao() {
}

Sessao::Sessao(string nome) {
    this->nome = nome;
}

ostream& operator <<(ostream &os, Sessao &s)  {

    os << "s_nome:" << s.nome << endl;
    os << "---" << endl;
    return os;
}

void Sessao::adicionaSecretaria(Secretaria secretaria) {
    this->secretarias.push_back(secretaria);
}
