#include <string>
#include <iostream>
#include "tablero.h"
#include "barcos.h"
#include "jugador.h"

using namespace std;

void verificarMinimo(int*, int*);
void ingresarCoordenadas(int, std::string*, int*);
void mostrarMatriz(int **, int, int);
void coordenadasCPU(int, int*, int, int, int*, int*, int*, int*);
void tirosCpu(int,int,int*,int*);

int main() {
    tablero t1(0,0); tablero t2(0,0); tablero tcpu(0,0);
    barcos b1; barcos b2; barcos bcpu;
    jugador j1; jugador j2; jugador cpu;
    int filas=0, columnas=0, xi, xf, yi, yf, tipoBarco, aciertos1 =0, aciertos2 =0, aciertosCpu=0;
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
        mostrarMatriz(matriz1, filas, columnas);
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
                    while (!b1.verificarCadena(coord, &tipoBarco) || (!b1.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i)) || (!b1.verificarSuperpuestos(matriz1, &xi, &xf, &yi, &yf, &tipoBarco))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                    }
                    t1.actualizarMatriz(matriz1, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                    mostrarMatriz(matriz1, filas, columnas);
                }
                cout << "--------------------------------------" << endl;
                cout << "------------- JUGADOR 2 --------------" << endl;
                mostrarMatriz(matriz2, filas, columnas);

                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord, &tipoBarco);
                    while (!b2.verificarCadena(coord, &tipoBarco) || (!b2.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i))|| (!b2.verificarSuperpuestos(matriz2, &xi, &xf, &yi, &yf, &tipoBarco))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                    }
                    t2.actualizarMatriz(matriz2, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                    mostrarMatriz(matriz2, filas, columnas);
                }
                //empiezan a disparar
                cout << "---------- A JUGAR ----------" << endl;
                while (aciertos1 < 18 && aciertos2 < 18) {
                    cout << "-------------- DISPARA J1 --------------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j1.verificarDisparo(coord, filas, columnas, &xi, &yi))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                    }
                    if (j1.disparar(disparos1, matriz2, &xi, &yi)) {
                        mostrarMatriz(disparos1, filas, columnas);
                        aciertos1++;
                    } else {
                        cout << "AGUA! (7)" << endl;
                        mostrarMatriz(disparos1, filas, columnas);
                    }
                    if (aciertos1 == 18){
                        cout << "GANA J1!";
                        break;
                    }
                    cout << "-------------- DISPARA J2 --------------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j2.verificarDisparo(coord, filas, columnas, &xi, &yi))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                    }
                    if (j2.disparar(disparos2, matriz1, &xi, &yi)) {
                        mostrarMatriz(disparos2, filas, columnas);
                        aciertos2++;
                    }
                    else {
                        cout << "AGUA! (7)" << endl;
                        mostrarMatriz(disparos2, filas, columnas);
                    }
                    if (aciertos2 == 18) {
                        cout << "GANA J2";
                        break;
                    }
                }
                break;
            case 2:
                cout << "---------- JUGADOR 1 ----------" << endl;
                for (int i = 1; i < 8; ++i) {
                    ingresarCoordenadas(i, &coord, &tipoBarco);
                    while (!b1.verificarCadena(coord, &tipoBarco) || (!b1.verificarCoordenadas(coord, filas, columnas, &xi, &xf, &yi, &yf, i)) || (!b1.verificarSuperpuestos(matriz1, &xi, &xf, &yi, &yf, &tipoBarco))){
                        cout << "Ingrese las coordenadas nuevamente:" << endl;
                        cin >> coord;
                    }
                    t1.actualizarMatriz(matriz1, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                    mostrarMatriz(matriz1, filas, columnas);
                }
                cout << "-------------------------" << endl;
                cout << "---------- CPU ----------" << endl;
                cout << "Ubicando barcos..."<< endl;
                for (int i = 1; i < 8; ++i) {
                    coordenadasCPU(i, &tipoBarco, filas, columnas, &xi, &xf, &yi, &yf);
                    while (!bcpu.verificarSuperpuestos(matrizCpu, &xi, &xf, &yi, &yf, &tipoBarco)){
                        coordenadasCPU(i, &tipoBarco, filas, columnas, &xi, &xf, &yi, &yf);
                    }
                    tcpu.actualizarMatriz(matrizCpu, filas, columnas, &xi, &xf, &yi, &yf, tipoBarco);
                }
                mostrarMatriz(matrizCpu, filas, columnas);
                cout << "-------------- A JUGAR --------------" << endl;
                while (aciertos1 < 18 && aciertosCpu < 18) {
                    cout << "-------------- DISPARA J1 --------------" << endl;
                    cout << "Ingrese las coordenadas del disparo!:";
                    cin >> coord;
                    while (!(j1.verificarDisparo(coord, filas, columnas, &xi, &yi))) {
                        cout << "Ingrese las coordenadas nuevamente:";
                        cin >> coord;
                    }
                    if (j1.disparar(disparos1, matrizCpu, &xi, &yi)) {
                        mostrarMatriz(disparos1, filas, columnas);
                        aciertos1++;
                    } else {
                        cout << "AGUA! (7)" << endl;
                        mostrarMatriz(disparos1, filas, columnas);
                    }
                    if (aciertos1 == 18){
                        cout << "GANA J1!";
                        break;
                    }
                    cout << "-------------- DISPARA CPU --------------" << endl;
                    tirosCpu(filas, columnas , &xi, &yi);
                    if ((matriz1[yi - 1][xi - 1] != 0)) {
                        disparosCpu[yi - 1][xi - 1] = matriz1[yi - 1][xi - 1];
                        mostrarMatriz(disparosCpu, filas, columnas);
                        aciertosCpu++;
                    } else {
                        cout << "AGUA! (7)" << endl;
                        disparosCpu[yi - 1][xi - 1] = 7;
                    }
                    if (aciertosCpu == 18){
                        cout << "GANA CPU";
                        break;
                    }
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
    for (int i = 0; i < filas; ++i) {
        delete[] matriz2[i];
    }
    delete[] matriz2;
    for (int i = 0; i < filas; ++i) {
        delete[] matrizCpu[i];
    }
    delete[] matrizCpu;

    return 0;
}


void verificarMinimo(int *filas, int *columnas) {
    while ((*filas < 9) || (*columnas < 9)){
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

void coordenadasCPU(int i, int * tipo, int filas, int columnas, int* xi, int* xf, int* yi,int* yf){
    srand(time(NULL));
    if (i==1){
        *tipo = 1;
    } else if (i == 2 || i == 3){
        *tipo = 2;
    } else if (i==4||i==5||i==6){
        *tipo = 3;
    } else {
        *tipo = 4;
    }
    *xi = 1 + rand() % (columnas-*tipo);
    *yi = 1 + rand() % (filas-*tipo);
    *xf = *xi + rand() % (*tipo);
    *yf = *yi + rand() % (*tipo);
    if (*tipo > 1) {
        while ((*xi == *xf && *yi == *yf) || (*xi != *xf && *yi != *yf) || (::abs(*xi-*xf) != (*tipo-1)) && (::abs(*yi-*yf) != (*tipo-1))){
            *xf = *xi + rand() % (*tipo);
            *yf = *yi + rand() % (*tipo);
        }
    }
}

void tirosCpu(int filas, int columnas, int* xi, int* yi) {
    *xi = 1 + rand() % (columnas);
    *yi = 1 + rand() % (filas);
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
