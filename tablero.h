//
// Created by agust on 18/5/2023.
//

#ifndef SUDOKU_TABLERO_H
#define SUDOKU_TABLERO_H

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

    void generarTablero(int f, int c);


};
class barcos : public tablero{
private:
    std::string coordenadas;
public:
    barcos();
    barcos(std::string coordenadas, int f, int c);

    void setCoordenadas(std::string _coordenadas) { coordenadas = _coordenadas;}

    std::string getCoordenadas() {return coordenadas;}

    void verificarBarcos();
    void ubicarBarcos(std::string coordenadas, int f, int c);

};

class jugador : public tablero{
private:
    std::string nombre;
public:
    jugador();
    jugador(std::string nombre, int f, int c);

    barcos B;

};


#endif //SUDOKU_TABLERO_H
