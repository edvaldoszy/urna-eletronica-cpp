#include <regex>
#include "Arquivo.h"

Arquivo::Arquivo() {

}

string Arquivo::line(ifstream &ifs) {
    string line;
    ifs >> line;
    return line;
}

void Arquivo::gravarSessao(Sessao sessao) {
    string path = "../data/sessao_" + sessao.nome + ".txt";
    ofstream ofs(path, fstream::trunc);
    if (!ofs.good()) {
        cout << "Falha ao criar o arquivo" << endl;
        exit(EXIT_FAILURE);
    }

    ofs << "sessao{" << endl;
    ofs << "\t" << sessao.nome << endl;
    gravaSecretarias(ofs, sessao.secretarias);
    ofs << "}" << endl;
}

void Arquivo::gravaSecretarias(ofstream &ofs, vector<Secretaria> secretarias) {
    for (Secretaria s : secretarias) {
        ofs << "\tsecretaria{" << endl;
        ofs << "\t\t" << s.nome << endl;
        gravaCandidatos(ofs, s.candidatos);
        ofs << "\t}" << endl;
    }
}

void Arquivo::gravaCandidatos(ofstream &ofs, vector<Candidato> candidatos) {
    ofs << "\t\tcandidatos{" << endl;
    for (Candidato c : candidatos) {
        ofs << "\t\t\t" << c.cargo << ";" << c.nome << ";" << c.votos << endl;
    }
    ofs << "\t\t}" << endl;
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
            secretaria.candidatos = candidatos;
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

        if (matches.size() == 4) {
            Candidato c(matches.str(1), matches.str(2), stoi(matches.str(3)));
            candidatos.push_back(c);
        }
    }

    return candidatos;
}
