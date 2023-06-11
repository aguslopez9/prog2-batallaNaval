#include <string>
#include <iostream>
#include "tablero.h"
#include "barcos.h"

using namespace std;

void verificarMinimo(int*, int*);
void ingresarCoordenadas(int, std::string*);
int main() {
    tablero t1(0,0);
    tablero t2(0,0);
    barcos b1;
    barcos b2;
    int filas=0, columnas=0, xi, xf, yi, yf;
    int** matriz1;
    int** matriz2;
    std::string coord;
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
                matriz1 = t1.matriz(filas, columnas);
                matriz2 = t2.matriz(filas, columnas);
                t1.mostrarTablero(filas, columnas, matriz1);
                cout << "Distribuir en el tablero 7 barcos por cada jugador.\n"
                        "- 1 barco de 1 casilla,\n"
                        "- 2 barcos de 2 casillas,\n"
                        "- 3 barcos de 3 casillas\n"
                        "- 1 barcos de 4 casillas\n"
                        "Los barcos no pueden superponerse!"<< endl;
                cout << "---------- JUGADOR 1 ----------" << endl;
                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord);
                    while (!b1.verificarCadena(coord) || (!b1.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                        b1.verificarCadena(coord);
                    }
                    t1.actualizarMatriz(matriz1, filas, columnas, &xi, &xf, &yi, &yf);
                }

                cout << "---------- JUGADOR 2 ----------" << endl;
                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord);
                    while (!b2.verificarCadena(coord) || (!b2.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                        b2.verificarCadena(coord);
                    }
                    t2.actualizarMatriz(matriz2, filas, columnas, &xi, &xf, &yi, &yf);
                }

                break;
            case 2:
                verificarMinimo(&filas, &columnas);

                //jvscpu();
                break;
            case 0:
                break;
            default:
                cout << "Ingrese una opcion valida." << endl;
                break;
        }
    } while (op != 0);

    for (int i = 0; i < filas; ++i) {
        delete[] matriz1[i];
    }
    delete[] matriz1;

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

void ingresarCoordenadas(int i, std::string *coordenadas) {
    switch (i) {
        case 1:
            cout << "Barco de 1 casilla" << endl;
            cout << "Coordenadas (Ej: A1A1):";
            cin >> *coordenadas;
            break;
        case 2:
        case 3:
            cout << "Barco de 2 casillas" <<endl;
            cout << "Coordenadas (Ej: A1A2):";
            cin >> *coordenadas;
            break;
        case 4:
        case 5:
        case 6:
            cout << "Barco de 3 casillas" <<endl;
            cout << "Coordenadas (Ej: A1A2):";
            cin >> *coordenadas;
            break;
        case 7:
            cout << "Barco de 4 casillas" << endl;
            cout << "Coordenadas (Ej: A1A2):";
            cin >> *coordenadas;
            break;
        default:
            break;
    }

}

