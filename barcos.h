//
// Created by agust on 11/6/2023.
//

#ifndef SUDOKU_BARCOS_H
#define SUDOKU_BARCOS_H
#include "tablero.h"

class barcos : public tablero {
private:
    std::string coordenadas;
public:
    barcos();
    barcos(std::string coordenadas, int f, int c);

    void setCoordenadas(std::string _coordenadas) { coordenadas = _coordenadas;}
    std::string getCoordenadas() {return coordenadas;}

    bool verificarCadena(std::string);
    bool verificarCoordenadas(std::string, int, int, int*, int*, int*, int*, int);


};

#endif //SUDOKU_BARCOS_H
