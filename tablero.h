//
// Created by agust on 18/5/2023.
//

#ifndef SUDOKU_TABLERO_H
#define SUDOKU_TABLERO_H
#include <vector>
#include <string>


class tablero {
private:
    int f, c;
public:
    tablero();
    tablero(int f, int c);

    void setF(int _f) {f=_f;}
    void setC(int _c) {c=_c;}

    int getF() {return f;}
    int getC() {return c;}

    int** matriz(int, int);
    void actualizarMatriz(int**, int, int, int*, int*, int*, int*);
    void mostrarTablero(int, int, int**);

};






#endif //SUDOKU_TABLERO_H
