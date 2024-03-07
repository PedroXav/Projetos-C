#include <iostream>
#include <vector>

using namespace std;

const int FILEIRAS = 15;
const int POLTRONAS = 40;
const double PRECO_Alto = 50.00;
const double PRECO_Medio = 30.00;
const double PRECO_Baixo = 15.00;

vector<vector<bool>> sala(FILEIRAS, vector<bool>(POLTRONAS, false));
double faturamento = 0.0;
int lugaresOcupados = 0;

double precoPoltrona(int fileira) {
    if (fileira >= 1 && fileira <= 5) return PRECO_Alto;
    if (fileira >= 6 && fileira <= 10) return PRECO_Medio;
    if (fileira >= 11 && fileira <= 15) return PRECO_Baixo;
    return 0.0;
}

void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Digite a fileira (1-15): ";
    cin >> fileira;
    cout << "Digite a poltrona (1-40): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > 15 || poltrona < 1 || poltrona > 40) {
        cout << "Fileira ou poltrona inválida." << endl;
        return;
    }

    if (!sala[fileira - 1][poltrona - 1]) {
        sala[fileira - 1][poltrona - 1] = true;
        faturamento += precoPoltrona(fileira);
        lugaresOcupados++;
        cout << "Reserva efetuada com sucesso!" << endl;
    } else {
        cout << "Lugar já está ocupado." << endl;
    }
}

void mapaOcupacao() {
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            if (sala[i][j]) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

void faturamentoAtual() {
    cout << "Qtde de lugares ocupados: " << lugaresOcupados << endl;
    cout << "Valor da bilheteria: R$ " << faturamento << endl;
}

int main() {
    int opcao;

    do {
        cout << "0. Finalizar\n1. Reservar poltrona\n2. Mapa de ocupação\n3. Faturamento\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                reservarPoltrona();
                break;
            case 2:
                mapaOcupacao();
                break;
            case 3:
                faturamentoAtual();
                break;
            case 0:
                cout << "Sistema finalizado." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}