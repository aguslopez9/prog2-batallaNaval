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

bool jugador::verificarDisparo(std::string coord) {
    if (!isalpha(coord[0])){
        return false;
    }
    for (int i = 1; i < coord.length(); ++i) {
        if (!isdigit(coord[i])){
            return false;
        }
    }
    return true;
}
bool jugador::disparar(int** disparos, int ** barcos,std::string _coordenadas) {
    std::string x = std::to_string((int)std::toupper(_coordenadas[0]) - 64);
    std::string y;
    for (int i = 1; i < _coordenadas.length(); ++i) {
        if (isdigit(_coordenadas[i])) {
            y += _coordenadas[i];
        }
    }
    int xi = std::stoi(x);
    int yi = std::stoi(y);

    if ((barcos[yi - 1][xi - 1] != 0)) {
        disparos[yi - 1][xi - 1] = barcos[yi - 1][xi - 1];
        return true;
    }
    return false;
}





