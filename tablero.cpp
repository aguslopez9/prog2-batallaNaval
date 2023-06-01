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

void tablero::generarTablero(int _f, int _c) {
    std::string columnas = "   |";
    std::string filas = "---+";
    cout << "  |";
    for (char col = 'A'; col < 'A'+_c; ++col) {
        cout << " "<<col << " |";
    }
    cout << endl;
    cout <<"--+";
    for (int j = 0; j < _c; ++j) {
        cout << filas;
    }
    cout << endl;

    for (int i = 0; i < _f; ++i) {
        cout << i+1 <<" |";
        for (int j = 0; j < _c; ++j) {
            cout << columnas;
        }
        cout << std::endl;
        cout <<"--+";
        for (int j = 0; j < _c; ++j) {
            cout << filas;
        }
        cout << endl;
    }
}


barcos::barcos() :barcos(0,0,0,0,"",0,0){}
barcos::barcos(int _numeroBarco, int _tamBarco, int _coordX, int _coordY, std::string _direccion, int _f, int _c) {
    numeroBarco = _numeroBarco;
    tamBarco = _tamBarco;
    coordX = _coordX;
    coordY = _coordY;
    direccion = _direccion;
}

jugador::jugador() :jugador("",0,0){}
jugador::jugador(std::string _nombre, int _f, int _c) {
    nombre = _nombre;
}

void jugador::ingresarNombre() {
    cout << "NOMBRE:";
    cin >> nombre;
}

void barcos::ubicarBarcos() {
    int *barcos = new int [7];
    for (int i = 0; i < 7; ++i) {
        cout << "Ingresar las coordenadas x e y del inicio y final del barco" << endl;
        switch (i+1) {
            case 1:
                cout << "Barco de 1 casilla";
                cout << "Coordenada X:";
                cin >> coordX;
                cout << "Coordenada Y:";
                cin >> coordY;
                break;
            case 2:
            case 3:
                cout << (i+1)<<"Barco de 2 casillas";
                break;
            case 4:
            case 5:
            case 6:
                cout << (i+1) <<"Barco de 3 casillas";
                break;
            case 7:
                cout <<(i+1) <<"Barco de 4 casillas";
                break;
        }
        cout << "Barco N" << i+1 << endl;
        if (i+1 == 1) {

        }
        cout << "Tamanio del barco";
    }
    int **barcos = new int *[7];

    for (int i = 0; i < 7; ++i) {
        barcos[i] = new int[7];
    }

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {

        }
    }

}


