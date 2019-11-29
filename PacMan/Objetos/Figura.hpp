/**!<Guardas de inclusión*/
#ifndef FIGURA_HPP
#define FIGURA_HPP

/**!<Biblioteca de cuadro*/
#include "../Graphics_Engine/Cuadro.hpp"

/**
 *@class Figura
 *@brief Representa a una figura capaz de moverse en el tablero
 */
class Figura : public Cuadro{

public:
    /**
     *@brief Método cosntructor de Figura
     */
    Figura();

    /**
     *@brief Método destructor de Figura
     */
    ~Figura();

    /**
     *@brief Método que mueve hacia arriba a la figura
     */
    void mueve_arriba();

    /**
     *@brief Método que mueve hacia abajo a la figura
     */
    void mueve_abajo();

    /**
     *@brief Método que mueve hacia la derecha la figura
     */
    void mueve_derecha();

    /**
     *@brief Método que mueve hacia la izquierda la figura
     */
    void mueve_izquierda();
};

Figura::Figura(/* args */)
{
}

Figura::~Figura()
{
}

void Figura::mueve_arriba(){

    this->posicion.y = this->posicion.y - 1;

}

void Figura::mueve_abajo(){

    this->posicion.y++;

}

void Figura::mueve_derecha(){

    this->posicion.x++;

}

void Figura::mueve_izquierda(){

    this->posicion.x--;

}

#endif  //FIGURA_HPP