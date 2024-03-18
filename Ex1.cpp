#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

void esperar(int milliseconds) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count() < milliseconds);
}

int main() {
    std::string mensagem;

    
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    
    int espacamento = (80 - mensagem.length()) / 2;

    
    for (int i = 0; i < 5; i++) {
        std::cout << std::endl;
    }
    std::cout << std::setw(espacamento) << mensagem << std::endl;

    
    srand(time(0)); 
    for (int linha = 6; linha <= 20; linha++) {
        esperar(100); 
        std::cout << std::setw(espacamento + rand() % 3) << std::string(linha, ' ') << mensagem << std::endl;
    }

    return 0;
}





