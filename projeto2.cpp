#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Estrutura para representar uma carta
struct Carta {
    int naipe; // 1-Copas / 2-Paus / 3-Ouro / 4-Espada
    int numero; // 1-Ás / 13-Rei
    int baralho; // 1 ou 2

    // Construtor
    Carta(int n, int num, int b) : naipe(n), numero(num), baralho(b) {}

    // Função para obter a representação da carta
    string getRepresentacao() const {
        return to_string(naipe) + "-" + (numero < 10 ? "0" : "") + to_string(numero) + "-" + to_string(baralho);
    }
};

int main() {
    // Inicializa o gerador de números aleatórios
    srand(time(nullptr));

    // Criação do baralho com as 52 cartas
    vector<Carta> baralho;
    for (int b = 1; b <= 2; ++b) {
        for (int n = 1; n <= 4; ++n) {
            for (int num = 1; num <= 13; ++num) {
                baralho.push_back(Carta(n, num, b));
            }
        }
    }

    // Embaralha o baralho
    random_shuffle(baralho.begin(), baralho.end());

    // Distribuição das cartas para os jogadores
    vector<vector<Carta>> mao(4, vector<Carta>(11));
    for (int j = 0; j < 4; ++j) {
        for (int c = 0; c < 11; ++c) {
            mao[j][c] = baralho.back();
            baralho.pop_back();
        }
    }

    // Apresenta as mãos dos jogadores
    for (int j = 0; j < 4; ++j) {
        cout << "Mão do Jogador " << j+1 << ":" << endl;
        for (int c = 0; c < 11; ++c) {
            cout << mao[j][c].getRepresentacao() << endl;
        }
        cout << endl;
    }

    return 0;
}
