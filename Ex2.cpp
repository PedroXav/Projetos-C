#include <iostream>
#include <string>
#include <algorithm>
#include <locale.h>

bool ehPalindromo(const std::string& texto) {
    std::string textoSemEspacos;
    for (char c : texto) {
        if (c != ' ') {
            textoSemEspacos.push_back(c);
        }
    }

    std::string textoReverso = textoSemEspacos;
    std::reverse(textoReverso.begin(), textoReverso.end());

    return textoSemEspacos == textoReverso;
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    std::string mensagem;

    
    std::cout << "Digite uma mensagem para verificar se é um palíndromo: ";
    std::getline(std::cin, mensagem);

   
    if (ehPalindromo(mensagem)) {
        std::cout << "A mensagem digitada é um palindromo." << std::endl;
    } else {
        std::cout << "A mensagem digitada nao é um palindromo." << std::endl;
    }

    return 0;
}
