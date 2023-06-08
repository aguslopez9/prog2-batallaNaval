#include <iostream>
#include "tablero.h"
using namespace std;

void verificarMinimo(int*, int*);
int ingresarBarcos(int*, int*, std::string*, int);
bool verificarCoordenadas(std::string);

int main() {
    barcos B1;
    barcos B2;
    tablero t(0,0);
    int filas=0, columnas=0;
    std::string coordenadas;
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
                cout << "Distribuir en el tablero 7 barcos por cada jugador.\n"
                        "- 1 barco de 1 casilla,\n"
                        "- 2 barcos de 2 casillas,\n"
                        "- 3 barcos de 3 casillas\n"
                        "- 1 barcos de 4 casillas\n"
                        "Los barcos no pueden superponerse!"<< endl;
                cout << "JUGADOR 1" << endl;
                for (int i = 0; i < 7; ++i) {
                    ingresarBarcos(&filas, &columnas, &coordenadas, i+1);
                    B1.ubicarBarcos(coordenadas, filas, columnas);
                }
                for (int i = 0; i < 7; ++i) {
                    ingresarBarcos(&filas, &columnas, &coordenadas, i+1);
                    B2.ubicarBarcos(coordenadas, filas, columnas);
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

int ingresarBarcos(int *filas, int *columnas, std::string *coordenadas, int i) {
    int f = *filas;
    int c = *columnas;
    std::string cord = *coordenadas;
    if (i == 1) {
        cout << "Barco de 1 casilla" << endl;
        cout << "Coordenadas (Ej: A1):";
        cin >> *coordenadas;
        *coordenadas = *coordenadas + *coordenadas;
        while(!verificarCoordenadas(*coordenadas)){
            cout << "Barco de 1 casilla" << endl;
            cout << "Coordenadas (Ej: A1):";
            cin >> *coordenadas;
            *coordenadas = *coordenadas + *coordenadas;
        }
    } else if (i > 1 and i < 4) {
        cout << "Barco de 2 casillas" << endl;
        cout << "Coordenadas Inicial-Final (Ej: A1A2):";
        cin >> *coordenadas;
        while(!verificarCoordenadas(*coordenadas)){
            cout << "Barco de 2 casillas" << endl;
            cout << "Coordenadas Inicial-Final (Ej: A1A2):";
            cin >> *coordenadas;
        }

    } else if (i > 4 and i < 6) {
        cout << "Barco de 3 casillas" << endl;
        cout << "Coordenadas Inicial-Final (Ej: A1A3):";
        cin >> *coordenadas;
        while(!verificarCoordenadas(*coordenadas)){
            cout << "Barco de 3 casillas" << endl;
            cout << "Coordenadas Inicial-Final (Ej: A1A3):";
            cin >> *coordenadas;
        }
    } else {
        cout << "Barco de 4 casillas" << endl;
        cout << "Coordenada Inicial-Final (Ej: A1A4):";
        cin >> *coordenadas;
        while(!verificarCoordenadas(*coordenadas)){
            cout << "Barco de 4 casillas" << endl;
            cout << "Coordenada Inicial-Final (Ej: A1A4):";
            cin >> *coordenadas;
        }
    }

}

bool verificarCoordenadas(std::string coordenadas) {
    if (coordenadas.length() < 4 || coordenadas.length() > 6) {
        return false;
    }

    bool valido = true;

    for (int i = 0; i < coordenadas.length(); i++) {
        if (i % 2 == 0) {
            if (!isalpha(coordenadas[i])) {
                valido = false;
                break;
            }
        } else {
            if (!isdigit(coordenadas[i])) {
                valido = false;
                break;
            }
        }
    }
    return valido;
}
