#include "Figura.hpp"

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