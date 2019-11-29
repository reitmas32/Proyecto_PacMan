#ifndef CUADRO_HPP
#define CUADRO_HPP

/**!<Se usara la biblioteca estandar de I/O de C++*/
#include <iostream>

/**!<Se utilizara la estructura vector*/
#include <vector>

/**!<API sobre la que se basa el pseudomotorgrafico*/ 
#include "miniwin.h"

/**!<BIblioteca que almacena los valores de los colores para el pseudomotorgrafico*/
#include "Colors.hpp"

/**!<Es el margen del Display*/
const int MARGEN = 25;

/**!<Es el tamaño que tendra cada cuadro*/
const int TAM = 20;

/**!<Estructura que almacena las coordenadas de cada cuadro respecto a todo el Display*/
typedef struct Coord{
    /**!<Posición con respecto a x y y*/
    int x, y;

    /**
     *@brief Método que rota a la derecha 90° un cuadro
     */
    void rota_derecha();
}Coord;

void Coord::rota_derecha(){
    int tmp = this->x;
    this->x = -this->y;
    this->y = tmp;
}

/**
 *@class Cuadro
 *@brief Cuadro base del juego
 */
class Cuadro
{
protected:
    /**!<Coordenada de posición del cuadro*/
    Coord posicion;

    /**!<Identificador del cuadro*/
    int id;

    /**!<Color solido del cuadro*/
    int colorSolido[3];

    /**!<Color de decoración del cuadro*/
    int colorDecora[3];
public:

    /**
     *@brief Método cosntructor del cuadro
     */
    Cuadro(/* args */);

    /**
     *@brief Método cosntructor del cuadro
     *
     *@param x Posición en x del cuadro
     *
     *@param y Posición en y del cuadro
     *
     *@param colorSolido[] Color solido del cuadro
     *
     *@param colorDecora[] color de decoración del cuadro
     */
    Cuadro(int x, int y, int colorSolido[], int colorDecora[]);

    /**
     *@brief Método destructor del cuadro 
     */
    ~Cuadro();

    /**
     *@brief Método que nos retoran la posición del cuadro
     */
    Coord getPosicion(){return this->posicion;}

    /**
     *@brief Método que nos da el color solido del cuadro
     *
     *@return matriz con el color solido del cuadro
     */
    int* getColorSolido(){return this->colorSolido;}

    /**
     *@brief Método que nos da el color de decoración del cuadro
     *
     *@return matriz con el colro de decoración del cuadro
     */
    int* getColorDecora(){return this->colorDecora;}

    /**
     *@brief Método que nos da el id del cuadro
     *
     *@return Id del cuadro 
     */
    int getId(){return this->id;}

    /**
     *@brief Método que define la posición del cuadro
     *
     *@param x Posición en x del caudro
     *
     *@param y Posición en y del cuadro 
     */

    void setPosicion(int x, int y){posicion.x = x; posicion.y = y;}

    /**
     *@brief Método que define el color solido del cuadro
     *
     *@param colorSolido[] Matriz con el color solido del cuadro
     */
    void setColorSolido(int colorSolido[]){
        for (size_t i = 0; i < 3; i++){
            this->colorSolido[i] = colorSolido[i];
        }
    }

    /**
     *@brief Método que define el color de decoración del cuadro
     *
     *@param colorDecora[] Matriz con el color de decoración del cuadro
     */
    void setColorDecora(int colorDecora[]){
        for (size_t i = 0; i < 3; i++){
            this->colorDecora[i] = colorDecora[i];
        }
    }

    /**
     *@brief Método que define él id del cuadro
     *
     *@param id Id del cuadro
     */
    void setId(int id){this->id = id;}

    /**
     *@brief Método que pitna el cuadro
     */
    void pinta();

    /**
     *@brief Método que solo pinta el cuadro con el color solido
     */
    void pintaSolido();
};

#if 1
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
    miniwin::color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
    //Se cambia el color para pintar en el color Decora del cuadro
    miniwin::color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );
    miniwin::rectangulo( MARGEN + 3 + this->getPosicion().x * TAM,
                MARGEN + 3 + this->getPosicion().y * TAM,
                MARGEN + this->getPosicion().x * TAM + TAM - 3,
                MARGEN + this->getPosicion().y * TAM + TAM - 3);
}

void Cuadro::pintaSolido(){
    //Se cambia el color para pintar en el color Solido del cuadro
    miniwin::color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM,
                        MARGEN + this->getPosicion().y * TAM + TAM);
}

Cuadro::~Cuadro()
{
}
#endif
#endif  //CUADRO_HPP