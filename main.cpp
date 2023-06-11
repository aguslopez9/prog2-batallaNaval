#include <iostream>
#include "tablero.h"
using namespace std;

void verificarMinimo(int*, int*);

int main() {
    jugador J1;
    jugador J2;
    tablero t(0,0);
    int filas=0, columnas=0;
    int op;
    do {
        cout << "---------------------------------" << endl;
        cout << "-------- Menu de opciones -------" << endl;
        cout << "---------------------------------" << endl;
        cout << "--------- 1. J1 vs J2 -----------" << endl;
        cout << "--------- 2. J vs CPU -----------" << endl;
        cout << "----------- 0. SALIR ------------" << endl;
        cout << "---------------------------------" << endl;
        cout << "Ingrese una opcion:";
        cin >> op;

        switch (op) {
            case 1:
                verificarMinimo(&filas, &columnas);
                t.generarTablero(filas, columnas);
                cout << "Distribuir en el tablero 7 barcos por cada jugador.\n"
                        "- 1 barco de 1 casilla,\n"
                        "- 2 barcos de 2 casillas,\n"
                        "- 3 barcos de 3 casillas\n"
                        "- 1 barcos de 4 casillas\n"
                        "Los barcos no pueden superponerse!"<< endl;
                cout << "JUGADOR 1" << endl;
                J1.generarMatrizJugador(filas, columnas);
                for (int i = 1; i <= 7; ++i) {
                    ingresarBarcos(filas, columnas, i);
                }
                J2.generarMatrizJugador(filas, columnas);
                for (int i = 1; i < 7; ++i) {
                    J2.ingresarBarcos(filas, columnas, i);
                }
                break;
            case 2:
                verificarMinimo(&filas, &columnas);
                t.generarTablero(filas, columnas);
                //jvscpu();
                break;
            case 0:
                break;
            default:
                cout << "Ingrese una opcion valida." << endl;
                break;
        }
    } while (op != 0);

    return 0;
}

void verificarMinimo(int *filas, int *columnas) {
    while ((*filas < 9) && (*columnas < 9)){
        cout << "El tablero debe ser de minimo 9x9!" << endl;
        cout << "Ingrese las filas del tablero:";
        cin >> *filas;
        cout << "Ingrese las columnas del tablero:";
        cin >> *columnas;
    }
}
