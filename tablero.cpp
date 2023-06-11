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



jugador::jugador() :jugador(0,0){}
void jugador::generarMatrizJugador(int _f, int _c) {
    int** matriz = new int*[_f];

    for (int i = 0; i < _f; ++i) {
        matriz[i] = new int[_c];
    }

    for (int i = 0; i < _f; ++i) {
        for (int j = 0; j < _c; ++j) {
            matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < 7; ++i) {
        B.ingresarBarcos(i, matriz);
    }
}

barcos::barcos() : barcos("", 0, 0){}
barcos::barcos(std::string _coordenadas, int _f, int _c) : tablero(_f, _c){
    coordenadas = _coordenadas;

}

bool barcos::verificarCoordenadas(std::string coordenadas) {
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
void barcos::ingresarBarcos(int i, int** matriz) {
        std::string coord;
        if (i == 1) {
            cout << "Barco de 1 casilla" << endl;
            cout << "Coordenadas (Ej: A1):";
            cin >> coord;
            coord = coord + coord;
            while(!verificarCoordenadas(coord)){
                cout << "Barco de 1 casilla" << endl;
                cout << "Coordenadas (Ej: A1):";
                cin >> coord;
                coord = coord + coord;
            }
        } else if (i > 1 and i < 4) {
            cout << "Barco de 2 casillas" << endl;
            cout << "Coordenadas Inicial-Final (Ej: A1A2):";
            cin >> coord;
            while(!verificarCoordenadas(coord)){
                cout << "Barco de 2 casillas" << endl;
                cout << "Coordenadas Inicial-Final (Ej: A1A2):";
                cin >> coord;
            }

        } else if (i >= 4 and i <= 6) {
            cout << "Barco de 3 casillas" << endl;
            cout << "Coordenadas Inicial-Final (Ej: A1A3):";
            cin >> coord;
            while(!verificarCoordenadas(coord)){
                cout << "Barco de 3 casillas" << endl;
                cout << "Coordenadas Inicial-Final (Ej: A1A3):";
                cin >> coord;
            }
        } else {
            cout << "Barco de 4 casillas" << endl;
            cout << "Coordenada Inicial-Final (Ej: A1A4):";
            cin >> coord;
            while(!verificarCoordenadas(coord)){
                cout << "Barco de 4 casillas" << endl;
                cout << "Coordenada Inicial-Final (Ej: A1A4):";
                cin >> coord;
            }
        }
    prepararCoordenadas(coord, matriz);
    }

void barcos::prepararCoordenadas(std::string _coordenadas, int** matriz) {

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

    int xIn = std::stoi(xI);
    int xFn = std::stoi(xF);
    int yIn = std::stoi(yI);
    int yFn = std::stoi(yF);

    ubicarBarcos(xIn, xFn, yIn, yFn, matriz);

}


void barcos::ubicarBarcos(int xIn, int xFn, int yIn, int yFn, int _c, int _f, int** matriz) {


    for (int i = 0; i < _c; ++i) {
        for (int j = 0; j < _f; ++j) {
            if (j + 1 >= yIn && j + 1 <= yFn && i + 1 >= xIn && i + 1 <= xFn) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < _f; ++i) {
        for (int j = 0; j < _c; ++j) {
            cout << matriz[j][i] << " ";
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
            if (matriz[j][i] == 1) {
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

    for (int i = 0; i < _f; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

}






