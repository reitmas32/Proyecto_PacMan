#ifndef CUADRO_HPP
#define CUADRO_HPP

/**!<Se usara la biblioteca estandar de I/O de C++*/
#include <iostream>

/**!<API sobre la que se basa el pseudomotorgrafico*/  
#include <motor_grafico/miniwin.hpp>

/**!<Es el margen del Display*/
const int MARGEN = 25;

/**!<Es el tamaño que tendra cada cuadro*/
const int TAM = 20;

/**!<Estructura que almacena las coordenadas de cada cuadro respecto a todo el Display*/
typedef struct Coord{
    /**!<Posición con respecto a x y y*/
    int x, y;
}Coord;

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
    int colorSolido;

    /**!<Color de decoración del cuadro*/
    int colorDecora;
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
     *@param colorSolido Color solido del cuadro
     *
     *@param colorDecora color de decoración del cuadro
     */
    Cuadro(int x, int y, int colorSolido, int colorDecora);

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
     *@return color solido del cuadro
     */
    int getColorSolido(){return this->colorSolido;}

    /**
     *@brief Método que nos da el color de decoración del cuadro
     *
     *@return el colro de decoración del cuadro
     */
    int getColorDecora(){return this->colorDecora;}

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
     *@param colorSolido es el color solido del cuadro
     */
    void setColorSolido(int colorSolido){
        this->colorSolido = colorSolido;
    }

    /**
     *@brief Método que define el color de decoración del cuadro
     *
     *@param colorDecora es el color de decoración del cuadro
     */
    void setColorDecora(int colorDecora){
        this->colorDecora = colorDecora;
    }

    /**
     *@brief Método que pitna el cuadro
     */
    void pinta();

    /**
     *@brief Método que solo pinta el cuadro con el color solido
     */
    void pintaSolido();
};

#endif  //CUADRO_HPP