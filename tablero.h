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
    int numeroBarco, tamBarco, coordX, coordY;
    std::string direccion;
public:
    barcos();
    barcos(int numeroBarco, int coordX, int coordY, int tamBarco, std::string direccion, int f, int c);

    void setNumeroBarco(int _numeroBarco) {numeroBarco = _numeroBarco;}
    void setTamBarco(int _tamBarco) {tamBarco = _tamBarco;}
    void setCoordX(int _coordX) {coordX = _coordX;}
    void setCoordXY(int _coordY) {coordY = _coordY;}
    void setDireccion(std::string _direccion) {direccion = _direccion;}

    int getNumeroBarco(){return numeroBarco;}
    int getTamBarco(){return tamBarco;}
    int getCoordX() {return coordX;}
    int getCoordY() {return coordY;}
    std::string getDireccion() {return direccion;}

    void ubicarBarcos();
};

class jugador : public tablero{
private:
    std::string nombre;
public:
    jugador();
    jugador(std::string nombre, int f, int c);

    void setNombre(std::string _nombre) {nombre=_nombre;}
    std::string getNombre(){return nombre;}

    void ingresarNombre();
};





#endif //SUDOKU_TABLERO_H
