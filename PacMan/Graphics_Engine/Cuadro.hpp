#ifndef CUADRO_HPP
#define CUADRO_HPP

/**
 * Se usara la biblioteca estandar de I/O de C++
 **/
#include <iostream>

/**
 * Se utilizara la estructura vector
 **/
#include <vector>

/**
 * API sobre la que se basa el pseudomotorgrafico
 **/ 
#include "miniwin.h"

/**
 * Es el margen del Display
 **/
const int MARGEN = 25;

/**
 * Es el tamaño que tendra cada cuadro
 **/
const int TAM = 20;

/**
 * Estructura que almacena las coordenadas de cada cuadro respecto a todo el Display
 **/
typedef struct Coord{
    int x, y;
}Coord;

//! Definicion de la Clase Cuadro de esta clase heredan todos los elementos del pseudomotorgrafico
class Cuadro
{
protected:
    Coord posicion;
    int colorSolido;
    int colorDecora;
public:
    Cuadro(/* args */);
    Cuadro(int x, int y, int colorSolido, int colorDecora);
    ~Cuadro();

    Coord getPosicion(){return this->posicion;}
    int getColorSolido(){return this->colorSolido;}
    int getColorDecora(){return this->colorDecora;}

    void setPosicion(int x, int y){posicion.x = x; posicion.y = y;}

    void setColorSolido(int colorSolido){
        this->colorSolido = colorSolido;
    }
    void setColorDecora(int colorDecora){
        this->colorDecora = colorDecora;
    }

    void pinta();

    void pintaSolido();
};

#endif  //CUADRO_HPP