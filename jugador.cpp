//
// Created by agust on 11/6/2023.
//
#include "jugador.h"
#include "barcos.h"
#include "tablero.h"
#include <string>
#include <iostream>
using namespace std;
jugador::jugador() : jugador(""){}
jugador::jugador(std::string _coordenadas) {
    coordenadas = _coordenadas;
}

bool jugador::verificarDisparo(std::string coord, int filas, int columnas, int* xi, int* yi) {
    std::string x = std::to_string((int)std::toupper(coord[0]) - 64);
    std::string y;
    if (!isalpha(coord[0])){
        return false;
    }
    for (int i = 1; i < coord.length(); ++i) {
        if (!isdigit(coord[i])){
            return false;
        }
    }
    for (int i = 1; i < coord.length(); ++i) {
        if (isdigit(coord[i])) {
            y += coord[i];
        }
    }
    *xi = std::stoi(x);
    *yi = std::stoi(y);
    if ((*xi<1||*xi>columnas) || (*yi<1||*yi>filas)){
        return false;
    }

    return true;
}
bool jugador::disparar(int** disparos, int ** barcos, int* xi, int* yi) {

    if ((barcos[*yi - 1][*xi - 1] != 0)) {
        disparos[*yi - 1][*xi - 1] = barcos[*yi - 1][*xi - 1];
        return true;
    }
    else {
        disparos[*yi - 1][*xi - 1] = 7;
        return false;
    }
}





