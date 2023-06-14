//
// Created by agust on 18/5/2023.
//
#include <iostream>
#include <string>
#include "tablero.h"
using namespace std;


tablero::tablero() :tablero(0,0){}
tablero::tablero(int _f, int _c) {
    f = _f;
    c = _c;
}

int** tablero::matriz(int _f, int _c) {
    int** matriz = new int*[_f];

    for (int i = 0; i < _f; ++i) {
        matriz[i] = new int[_c];
        for (int j = 0; j < _c; ++j) {
            matriz[i][j] = 0;
        }
    }
    return matriz;
}

void tablero::actualizarMatriz(int ** matriz, int _f, int _c, int* xi, int* xf, int* yi, int* yf, int tipo) {
    for (int i = 0; i < _c; ++i) {
        for (int j = 0; j < _f; ++j) {
            if (j + 1 >= *yi && j + 1 <= *yf && i + 1 >= *xi && i + 1 <= *xf) {
                matriz[j][i] = tipo;
            }
        }
    }
}










