#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;
const double PRECO_FILEIRAS[] = {50.0, 50.0, 50.0, 50.0, 50.0, 30.0, 30.0, 30.0, 30.0, 30.0, 15.0, 15.0, 15.0, 15.0, 15.0};

char mapaOcupacao[NUM_FILEIRAS][POLTRONAS_POR_FILEIRA];

void inicializarMapa() {
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            mapaOcupacao[i][j] = '.';
        }
    }
}

void mostrarMapa() {
    cout << "Mapa de Ocupa��o:" << endl;
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            cout << mapaOcupacao[i][j];
        }
        cout << endl;
    }
}

void reservarPoltrona() {
    int fileira, poltrona;
    cout << "Digite a fileira (1 a 15): ";
    cin >> fileira;
    cout << "Digite a poltrona (1 a 40): ";
    cin >> poltrona;

    if (fileira < 1 || fileira > NUM_FILEIRAS || poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
        cout << "Fileira ou poltrona inv�lida." << endl;
        return;
    }

    if (mapaOcupacao[fileira - 1][poltrona - 1] == '#') {
        cout << "Esta poltrona j� est� ocupada." << endl;
    } else {
        mapaOcupacao[fileira - 1][poltrona - 1] = '#';
        cout << "Poltrona reservada com sucesso!" << endl;
    }
}

void calcularFaturamento() {
    int lugaresOcupados = 0;
    double faturamento = 0.0;
    for (int i = 0; i < NUM_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            if (mapaOcupacao[i][j] == '#') {
                lugaresOcupados++;
                faturamento += PRECO_FILEIRAS[i];
            }
        }
    }
    cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << "Valor total da bilheteria: R$ " << fixed << setprecision(2) << faturamento << endl;
}

int main() {
    int opcao;

    inicializarMapa();

    do {
        cout << "\nSelecione uma op��o:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupa��o" << endl;
        cout << "3. Faturamento" << endl;
        cout << "Op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Finalizando o programa." << endl;
                break;
            case 1:
                reservarPoltrona();
                break;
            case 2:
                mostrarMapa();
                break;
            case 3:
                calcularFaturamento();
                break;
            default:
                cout << "Op��o inv�lida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);

    return 0;
}
