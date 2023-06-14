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

    bool verificarDisparo(std::string, int, int, int*, int*);
    bool disparar(int**, int**, int*, int*);

    tablero t;
};

#endif //SUDOKU_JUGADOR_H
