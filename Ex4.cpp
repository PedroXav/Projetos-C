#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string transformarNome(const std::string& nomeCompleto) {
    std::stringstream ss(nomeCompleto);
    std::string sobrenome;
    std::vector<std::string> nomes;

    
    while (ss >> sobrenome) {
        nomes.push_back(sobrenome);
    }

    
    std::string nomeFormatado;
    if (!nomes.empty()) {
        nomeFormatado = nomes.back() + ", ";
        nomes.pop_back();
        if (!nomes.empty()) {
            
            for (size_t i = 0; i < nomes.size(); ++i) {
                nomeFormatado += nomes[i].substr(0, 1);
                nomeFormatado += ". ";
            }
        }
    }

    return nomeFormatado;
}

int main() {
    std::ifstream arquivo("nomes.txt");
    std::ofstream saida("nomes_citacao.txt");

    if (!arquivo.is_open() || !saida.is_open()) {
        std::cerr << "Erro ao abrir os arquivos." << std::endl;
        return 1;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::string nomeFormatado = transformarNome(linha);
        saida << nomeFormatado << std::endl;
    }

    std::cout << "Nomes transformados com sucesso." << std::endl;

    arquivo.close();
    saida.close();

    return 0;
}
