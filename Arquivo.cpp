#include <regex>
#include "Arquivo.h"

Arquivo::Arquivo() {

}

string Arquivo::line(ifstream &ifs) {
    string line;
    ifs >> line;
    return line;
}

Sessao Arquivo::carregarArquivo(string path) {
    ifstream ifs(path, fstream::app);
    if (!ifs.good()) {
        cout << "Falha ao abrir o arquivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line(Arquivo::line(ifs));

    if (line.compare("sessao{") == 0) {
        return Arquivo::carregaSessao(ifs);

    } else {
        cout << "Falha ao ler o arquivo" << endl;
        exit(EXIT_FAILURE);
    }
}

Sessao Arquivo::carregaSessao(ifstream &ifs) {
    Sessao sessao(Arquivo::line(ifs));

    while (!ifs.eof()) {
        string line(Arquivo::line(ifs));
        if (line.compare("secretaria{") == 0) {
            Secretaria secretaria = carregaSecretaria(ifs);
            sessao.adicionaSecretaria(secretaria);
            continue;

        } else if (line.compare("}") == 0) {
            break;
        }
    }

    return sessao;
}

Secretaria Arquivo::carregaSecretaria(ifstream &ifs) {
    Secretaria secretaria(Arquivo::line(ifs));

    while (!ifs.eof()) {
        string line(Arquivo::line(ifs));
        if (line.compare("candidatos{") == 0) {
            vector<Candidato> candidatos = carregaCandidatos(ifs);
            secretaria.setCandidatos(candidatos);
            continue;

        } else if (line.compare("}") == 0) {
            break;
        }
    }

    return secretaria;
}

vector<Candidato> Arquivo::carregaCandidatos(ifstream &ifs) {
    vector<Candidato> candidatos;

    while (!ifs.eof()) {
        string line(Arquivo::line(ifs));

        if (line.compare("}") == 0) {
            break;
        }

        std::cmatch matches;
        std::regex_match(line.c_str(), matches, std::regex("^([a-zA-Z]+);([a-zA-Z]+);([0-9]+)$"));
        //cout << "matches: " << matches.size() << endl;

        if (matches.size() == 4) {
            Candidato c(matches.str(1), matches.str(2), stoi(matches.str(3)));
            candidatos.push_back(c);
        }
    }

    return candidatos;
}
