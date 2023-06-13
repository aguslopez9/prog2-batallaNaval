//
// Created by agust on 11/6/2023.
//

#include "barcos.h"
#include "tablero.h"
#include <string>
#include <cmath>

using namespace std;

barcos::barcos() : barcos("",0,0){}
barcos::barcos(std::string _coordenadas,int _f, int _c)
: tablero(_f, _c){
    coordenadas = _coordenadas;
}
bool barcos::verificarCadena(std::string coordenadas) {
    int letrasSeguidas = 0, numerosSeguidos = 0 ,letras=0, numeros=0;
    if (coordenadas.length() < 4 || coordenadas.length() > 6) {
        return false;
    }
    if (!isalpha(coordenadas[0])){
        return false;
    }
    if (isalpha(coordenadas[-1])){
        return false;
    }

    for (int i = 1; i < coordenadas.length(); ++i) {
        if (isalpha(coordenadas[i])){
            letras++;
            letrasSeguidas++;
            numerosSeguidos = 0;
        } else if (isdigit(coordenadas[i])){
            numeros++;
            numerosSeguidos++;
            letrasSeguidas = 0;
        }

        if (letrasSeguidas > 1 || numerosSeguidos > 2 || letras > 2 || numeros > 4) {
            return false;
        }
    }

    return true;
}

bool barcos::verificarCoordenadas(std::string _coordenadas, int f, int c, int* xIn, int* xFn, int* yIn, int* yFn, int indice) {
    int indiceXf = 0;
    std::string xI = std::to_string((int) toupper(_coordenadas[0]) - 64);
    std::string yI, xF, yF;
    bool esLet = false;
    for (int i = 1; i <= _coordenadas.length(); ++i) {
        if (isalpha(_coordenadas[i])) {
            esLet = true;
        }
        if (esLet) {
            indiceXf = i;
            if (xF.empty()) {
                xF = std::to_string((int) toupper(_coordenadas[i]) - 64);
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

    *xIn = std::stoi(xI);
    *xFn = std::stoi(xF);
    *yIn = std::stoi(yI);
    *yFn = std::stoi(yF);


    if (*xIn > *xFn || *yIn > *yFn){
        return false;
    }
    if ((*xIn < 0 || *xIn > c) || (*xFn < 0 || *xFn > c)){
        return false;
    }
    else if ((*yIn < 0 || *yIn > f) || (*yFn < 0 || *yFn > f)){
        return false;
    }

    if (indice == 1){
        if (*xIn!=*xFn || *yIn!=*yFn){return false;}
    }
    else if (indice == 2 || indice == 3) {
        if (*xIn==*xFn && ::abs(*yIn-*yFn) != 1){return false;}
        else if (*yIn==*yFn && ::abs(*xIn-*xFn) != 1) {return false;}
    }
    else if (indice == 4 || indice == 5 || indice == 6){
        if (*xIn==*xFn && ::abs(*yIn-*yFn) != 2){return false;}
        else if (*yIn==*yFn && ::abs(*xIn-*xFn) != 2) {return false;}
    }
    else {
        if (*xIn==*xFn && ::abs(*yIn-*yFn) != 3){return false;}
        else if (*yIn==*yFn && ::abs(*xIn-*xFn) != 3) {return false;}
    }

    if ((*xIn!=*xFn) && (*yIn!=*yFn)){
        return false;
    }
    return true;

}

bool barcos::verificarSuperpuestos(int ** matriz, int* xi, int* xf, int* yi, int* yf) {

    if ((matriz[*yi-1][*xi-1] != 0) || (matriz[*yf-1][*xf-1] != 0)) {
        return false;
    }
    return true;
}
