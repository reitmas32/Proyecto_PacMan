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
 * BIblioteca que almacena los valores de los colores para el pseudomotorgrafico
 **/
#include "Colors.hpp"

using namespace miniwin;

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
    void rota_derecha();
}Coord;

/**
 * Metodo que rota cada cuador 90° ala derecha
 **/
void Coord::rota_derecha(){
    int tmp = this->x;
    this->x = -this->y;
    this->y = tmp;
}

//! Definicion de la Clase Cuadro de esta clase heredan todos los elementos del pseudomotorgrafico
class Cuadro
{
protected:
    Coord posicion;
    int id;
    int colorSolido[3];
    int colorDecora[3];
public:
    Cuadro(/* args */);
    Cuadro(int x, int y, int colorSolido[], int colorDecora[]);
    ~Cuadro();

    Coord getPosicion(){return this->posicion;}
    int* getColorSolido(){return this->colorSolido;}
    int* getColorDecora(){return this->colorDecora;}
    int getId(){return this->id;}

    void setPosicion(int x, int y){posicion.x = x; posicion.y = y;}

    void setColorSolido(int colorSolido[]){
        for (size_t i = 0; i < 3; i++){
            this->colorSolido[i] = colorSolido[i];
        }
    }
    void setColorDecora(int colorDecora[]){
        for (size_t i = 0; i < 3; i++){
            this->colorDecora[i] = colorDecora[i];
        }
    }
    void setId(int id){this->id = id;}

    void pinta();

    void pintaSolido();
};

Cuadro::Cuadro(/* args */)
{
}

Cuadro::Cuadro(int x, int y, int colorSolido[], int colorDecora[])
{
    
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

void Cuadro::pinta(){
    //Se cambia el color para pintar en el color Solido del cuadro
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
    //Se cambia el color para pintar en el color Decora del cuadro
    color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );
    rectangulo( MARGEN + 3 + this->getPosicion().x * TAM,
                MARGEN + 3 + this->getPosicion().y * TAM,
                MARGEN + this->getPosicion().x * TAM + TAM - 3,
                MARGEN + this->getPosicion().y * TAM + TAM - 3);
}

void Cuadro::pintaSolido(){
    //Se cambia el color para pintar en el color Solido del cuadro
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
}

Cuadro::~Cuadro()
{
}

#endif  //CUADRO_HPP