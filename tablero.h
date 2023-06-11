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

    void ingresarBarcos(int, int**);
    bool verificarCoordenadas(std::string);
    void prepararCoordenadas(std::string, int**);
    void ubicarBarcos(int, int, int, int, int, int);

};

class jugador : public tablero{

public:
    jugador();
    jugador(int f, int c);

    void generarMatrizJugador(int, int);
    void mostrarMatrizJugador(int, int);


    barcos B;

};


#endif //SUDOKU_TABLERO_H
