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
barcos::barcos() :barcos("",0,0){}
barcos::barcos(std::string _coordenadas, int _f, int _c) {
    coordenadas = _coordenadas;
}

void barcos::ubicarBarcos(std::string _coordenadas, int _f, int _c) {
    int indiceXf = 0;
    std::string xI = to_string((int) toupper(_coordenadas[0]) - 64);
    std::string yI, xF, yF;
    bool esLet = false;
    for (int i = 1; i <= _coordenadas.length(); ++i) {
        if (isalpha(_coordenadas[i])) {
            esLet = true;
        }
        if (esLet) {
            indiceXf = i;
            if (xF.empty()) {
                xF = to_string((int) toupper(_coordenadas[i]) - 64);
                esLet = false;
            }
        }
    }
    for (int i = 1; i < _coordenadas.length(); ++i) {
        if (i < indiceXf) {
            yI += ((_coordenadas[i]));
        }
        else if (i > indiceXf){
            yF += ((_coordenadas[i]));
        }
    }

    cout << "XI:"<<xI << " -XF:" <<xF<< " -YI:"<<yI <<" -YF:"<<yF << endl;

    int xIn = std::stoi(xI);
    int xFn = std::stoi(xF);
    int yIn = std::stoi(yI);
    int yFn = std::stoi(yF);
    cout << "XI:"<<xIn << " -XF:" <<xFn<< " -YI:"<<yIn <<" -YF:"<<yFn << endl;

    int matriz [_f][_c];

    for (int i = 0; i < _c; ++i) {
        for (int j = 0; j < _f; ++j) {
            if (j + 1 >= yIn && j + 1 <= yFn && i + 1 >= xIn && i + 1 <= xFn) {
                matriz[j][i] = 1;
            } else {
                matriz[j][i] = 0;
            }
        }
    }

    for (int i = 0; i < _c; ++i) {
        for (int j = 0; j < _f; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    std::string columnas = "|";
    std::string filas = "---+";
    cout << "  |";
    for (char col = 'A'; col < 'A' + _c; ++col) {
        cout << " " << col << " |";
    }
    cout << endl;
    cout << "--+";
    for (int j = 0; j < _c; ++j) {
        cout << filas;
    }
    cout << endl;

    for (int i = 0; i < _f; ++i) {
        cout << i + 1 << " |";
        for (int j = 0; j < _c; ++j) {
            if ((matriz[i][j]) == 1) {
                cout << " X " << columnas;
            } else {
                cout << "   " << columnas;
            }
        }
        cout << endl;
        cout << "--+";
        for (int j = 0; j < _c; ++j) {
            cout << filas;
        }
        cout << endl;
    }

}



