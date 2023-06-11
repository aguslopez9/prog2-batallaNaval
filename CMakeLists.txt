cmake_minimum_required(VERSION 3.24)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku main.cpp tablero.h tablero.cpp barcos.h barcos.cpp jugador.h jugador.cpp)
