#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int NUM_CARTAS = 52;
    const int NUM_JOGADORES = 4;
    const int NUM_CARTAS_MAO = 11;

    
    std::string baralho[NUM_CARTAS];
    for (int i = 0; i < NUM_CARTAS; i++) {
        baralho[i] = std::to_string((i % 13) + 1) + "-" + std::to_string((i / 13) + 1);
    }

    
    std::srand(std::time(nullptr));
    std::string maos[NUM_JOGADORES][NUM_CARTAS_MAO];
    for (int j = 0; j < NUM_JOGADORES; j++) {
        for (int c = 0; c < NUM_CARTAS_MAO; c++) {
            int indice_carta = std::rand() % NUM_CARTAS;
            maos[j][c] = baralho[indice_carta];
        }
    }

    
    for (int j = 0; j < NUM_JOGADORES; j++) {
        std::cout << "Mão do Jogador " << j+1 << ": ";
        for (int c = 0; c < NUM_CARTAS_MAO; c++) {
            std::cout << maos[j][c] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

