#include "Comida.hpp"

Comida::Comida(int x, int y, int colorSolido, int colorDecora)
{
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

Comida::Comida(/* args */)
{
}

Comida::~Comida()
{
}

void Comida::pinta(){
    miniwin::color(getColorSolido());
    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 6,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 6,
                                 MARGEN + 1 + this->getPosicion().x * TAM + 8,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 8);
}

void Comida::pintaGrande(){
    miniwin::color(getColorSolido());
    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + 7,
                            MARGEN + 1 + this->getPosicion().y * TAM + 6,3);
}