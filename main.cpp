#include <string>
#include <iostream>
#include "tablero.h"
#include "barcos.h"
#include "jugador.h"

using namespace std;

void verificarMinimo(int*, int*);
void ingresarCoordenadas(int, std::string*, int*);
void mostrarMatriz(int **, int, int);
void coordenadasCPU(int, std::string*, int*, int);

int main() {
    tablero t1(0,0); tablero t2(0,0); tablero tcpu(0,0);
    barcos b1; barcos b2; barcos bcpu;
    jugador j1; jugador j2; jugador cpu;
    int filas=0, columnas=0, xi, xf, yi, yf, tipoBarco, aciertos1 =0, aciertos2 =0;
    int** matriz1; int** matriz2; int** matrizCpu ;int** disparos1; int** disparos2; int** disparosCpu;
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
        verificarMinimo(&filas, &columnas);
        matriz1 = t1.matriz(filas, columnas); matriz2 = t2.matriz(filas, columnas); matrizCpu = tcpu.matriz(filas, columnas);
        disparos1 = t1.matriz(filas, columnas); disparos2 = t2.matriz(filas, columnas); disparosCpu = tcpu.matriz(filas,columnas);
        t1.mostrarTablero(filas, columnas, matriz1, tipoBarco=5);
        cout << "Distribuir en el tablero 7 barcos por cada jugador.\n"
                "- 1 lancha '1' (1 casilla),\n"
                "- 2 buques '2' (2 casillas),\n"
                "- 3 submarinos '3' (3 casillas)\n"
                "- 1 portaaviones '4' (4 casillas)\n"
                "Los barcos no pueden superponerse!"<< endl;
        switch (op) {
            case 1:
                cout << "---------- JUGADOR 1 ----------" << endl;
                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord, &tipoBarco);
                    while (!b1.verificarCadena(coord) || (!b1.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i)) || (!b1.verificarSuperpuestos(matriz1, &xi, &xf, &yi, &yf))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                        b1.verificarCadena(coord);
                    }
                    t1.actualizarMatriz(matriz1, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                }
                cout << "--------------------------------------" << endl;
                cout << "---------- JUGADOR 2 ----------" << endl;
                t2.mostrarTablero(filas, columnas, matriz2, tipoBarco=5);

                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord, &tipoBarco);
                    while (!b2.verificarCadena(coord) || (!b2.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i))|| (!b2.verificarSuperpuestos(matriz2, &xi, &xf, &yi, &yf))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                        b2.verificarCadena(coord);
                    }
                    t2.actualizarMatriz(matriz2, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                }
                //empiezan a disparar
                cout << "---------- A JUGAR ----------" << endl;
                while (aciertos1 < 18 && aciertos2 < 18) {
                    cout << "---------- DISPARA J1 ----------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j1.verificarDisparo(coord))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                        j1.verificarDisparo(coord);
                    }
                    if (j1.disparar(disparos1, matriz2, coord)) {
                        mostrarMatriz(disparos1, filas, columnas);
                        aciertos1++;
                    }
                    cout << "---------- DISPARA J2 ----------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j2.verificarDisparo(coord))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                        j2.verificarDisparo(coord);
                    }
                    if (j2.disparar(disparos2, matriz1, coord)) {
                        mostrarMatriz(disparos1, filas, columnas);
                        aciertos2++;
                    }
                }
                    if (aciertos1 == 18){
                    cout << "GANA J1!";
                    }
                    else if (aciertos2 == 18){
                        cout << "GANA J2";
                    }
                break;
            case 2:
                cout << "---------- JUGADOR 1 ----------" << endl;
                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord, &tipoBarco);
                    while (!b1.verificarCadena(coord) || (!b1.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i)) || (!b1.verificarSuperpuestos(matriz1, &xi, &xf, &yi, &yf))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                        b1.verificarCadena(coord);
                    }
                    t1.actualizarMatriz(matriz1, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                }
                for (int i = 1; i < 8; ++i) {
                    cout << "Ubicando barco n" << i << endl;
                    coordenadasCPU(i, &coord, &tipoBarco, filas);
                    cout << coord << endl;
                    while (!bcpu.verificarCadena(coord) || (!bcpu.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i))|| (!bcpu.verificarSuperpuestos(matriz2, &xi, &xf, &yi, &yf))){
                        coordenadasCPU(i, &coord, &tipoBarco, filas);
                        bcpu.verificarCadena(coord);
                    }
                    tcpu.actualizarMatriz(matrizCpu, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                }

                cout << "---------- A JUGAR ----------" << endl;
                while (aciertos1 < 18 && aciertos2 < 18) {
                    cout << "---------- DISPARA J1 ----------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j1.verificarDisparo(coord))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                        j1.verificarDisparo(coord);
                    }
                    if (j1.disparar(disparos1, matriz2, coord)) {
                        mostrarMatriz(disparos1, filas, columnas);
                        aciertos1++;
                    }
                    cout << "---------- DISPARA J2 ----------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j2.verificarDisparo(coord))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                        j2.verificarDisparo(coord);
                    }
                    if (j2.disparar(disparos2, matriz1, coord)) {
                        mostrarMatriz(disparos1, filas, columnas);
                        aciertos2++;
                    }
                }
                if (aciertos1 == 18){
                    cout << "GANA J1!";
                }
                else if (aciertos2 == 18){
                    cout << "GANA J2";
                }
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

void ingresarCoordenadas(int i, std::string *coordenadas, int * tipoBarco) {
    switch (i) {
        case 1:
            cout << "Barco de 1 casilla" << endl;
            cout << "Coordenadas (Ej: A1A1):";
            cin >> *coordenadas;
            *tipoBarco = 1;
            break;
        case 2:
        case 3:
            cout << "Barco de 2 casillas" <<endl;
            cout << "Coordenadas (Ej: A1A2):";
            cin >> *coordenadas;
            *tipoBarco = 2;
            break;
        case 4:
        case 5:
        case 6:
            cout << "Barco de 3 casillas" <<endl;
            cout << "Coordenadas (Ej: A1A2):";
            cin >> *coordenadas;
            *tipoBarco = 3;
            break;
        case 7:
            cout << "Barco de 4 casillas" << endl;
            cout << "Coordenadas (Ej: A1A2):";
            cin >> *coordenadas;
            *tipoBarco = 4;
            break;
        default:
            break;
    }

}

void coordenadasCPU(int i, std::string *coordenadas, int * tipoBarco, int filas){
    srand(time(NULL));

    char xi = 'A' + rand() % 26;
    int yi = 1 + rand() % (filas - 1);

    std::string cadena = xi + std::to_string(yi);
    switch (i) {
        case 1:
            *coordenadas = cadena = xi + std::to_string(yi) + xi + std::to_string(yi);;
            *tipoBarco = 1;
            break;
        case 2:
        case 3:
            *coordenadas = cadena;
            *tipoBarco = 2;
            break;
        case 4:
        case 5:
        case 6:
            *coordenadas = cadena;
            *tipoBarco = 3;
            break;
        case 7:
            *coordenadas = cadena;
            *tipoBarco = 4;
            break;
        default:
            break;
    }
}

void mostrarMatriz(int ** matriz, int f, int c){
    std::string columnas = "|";
    std::string filas = "---+";
    cout << "  |";
    for (char col = 'A'; col < 'A' + c; ++col) {
        cout << " " << col << " |";
    }
    cout << endl;
    cout << "--+";
    for (int j = 0; j < c; ++j) {
        cout << filas;
    }
    cout << endl;

    for (int i = 0; i < f; ++i) {
        cout << i + 1 << " |";
        for (int j = 0; j < c; ++j) {
            if ((matriz[i][j]) != 0) {
                cout << " "<<matriz[i][j]<<" " << columnas;
            } else {
                cout << "   " << columnas;
            }
        }
        cout << endl;
        cout << "--+";
        for (int j = 0; j < c; ++j) {
            cout << filas;
        }
        cout << endl;
    }
}
