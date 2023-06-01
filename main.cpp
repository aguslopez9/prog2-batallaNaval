#include <iostream>
#include "tablero.h"
using namespace std;

void verificarMinimo(int*, int*);
void ingresarBarcos(int*, int*);
void verificarBarco(int, int, int, int, int, int);


void j1vsj2(int, int);
void jvscpu(int, int);
int main() {
    jugador j1;
    barcos B1;
    jugador j2;
    barcos B2;
    tablero t(0,0);
    int filas=0, columnas=0;
    int op;
    do {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "-------- Menu de opciones -------" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "--------- 1. J1 vs J2 -----------" << std::endl;
        std::cout << "--------- 2. J vs CPU -----------" << std::endl;
        std::cout << "----------- 0. SALIR ------------" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Ingrese una opcion:";
        std::cin >> op;

        switch (op) {
            case 1:
                verificarMinimo(&filas, &columnas);
                t.generarTablero(filas, columnas);
                cout << "JUGADOR 1";
                j1.ingresarNombre();
                ingresarBarcos(&filas, &columnas);
                B1.ubicarBarcos();

                //j1vsj2(filas, columnas, j1(), j2());
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

void ingresarBarcos(int *filas, int *columnas) {
    int f = *filas;
    int c = *columnas;
    cout << "Distribuir en el tablero 7 barcos por cada jugador.\n"
            "◦ 1 barco 4 casillas,\n"
            "◦ 3 barcos de 3 casillas,\n"
            "◦ 2 barcos de 2 casillas\n"
            "◦ 1 barcos de 1 casillas" << endl;

    for (int i = 0; i < 7; ++i) {
        int xI=0, yI=0, xF=0, yF=0;
        switch (i + 1) {
            case 1:
                cout << "Barco de 1 casilla" << endl;
                cout << "Coordenada X:";
                cin >> xI;
                xF = xI;
                cout << "Coordenada Y:";
                cin >> yI;
                yF = yI;
                verificarBarco(xI, xF, yI, yF, f, c);
                break;
            case 2:
            case 3:
                cout << "Barco de 2 casillas" << endl;
                cout << "Coordenada X inicial:";
                cin >> xI;
                cout << "Coordenada X final:";
                cin >> xF;
                cout << "Coordenada Y inicial:";
                cin >> yI;
                cout << "Coordenada Y final:";
                cin >> yF;
                break;
            case 4:
            case 5:
            case 6:
                cout << "Barco de 3 casilla" << endl;
                break;
            case 7:
                cout << "Barco de 4 casilla" << endl;
                break;
        }
    }
}

void verificarBarco(int xI, int xF, int yI, int yF, int f, int c) {
    while (xI < 0 || xF < 0 || xI > f || xF > f || yI < 0 || yF < 0 || yI > c || yF > c) {

    }
}
