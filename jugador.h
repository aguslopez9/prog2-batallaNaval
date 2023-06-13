//
// Created by agust on 11/6/2023.
//

#ifndef SUDOKU_JUGADOR_H
#define SUDOKU_JUGADOR_H
#include <string>
#include "tablero.h"
#include "barcos.h"

class jugador {
private:
    std::string coordenadas;
public:
    jugador();
    jugador(std::string coordenadas);

    bool verificarDisparo(std::string);
    bool disparar(int**, int**,std::string);

    tablero t;
};

#endif //SUDOKU_JUGADOR_H
