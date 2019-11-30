#include "Fantasma.hpp"

Fantasma::Fantasma(/* args */)
{
}

Fantasma::Fantasma(int x, int y, int colorSolido, int colorDecora)
{
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

Fantasma::~Fantasma()
{
}

void Fantasma::pinta(){

    miniwin::color(getColorSolido());

    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 9,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 7,
                                 8);

    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 2,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 5,
                                 MARGEN + this->getPosicion().x * TAM + TAM - 2,
                                 MARGEN + this->getPosicion().y * TAM + TAM - 3);

    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 9,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 16,
                                 2);
    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 4,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 16,
                                 2);
    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 14,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 16,
                                 2);

    miniwin::color(getColorDecora());

    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 5,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 2,
                                 MARGEN + 1 + this->getPosicion().x * TAM + 7,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 4);

    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 10,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 2,
                                 MARGEN + 1 + this->getPosicion().x * TAM + 12,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 4);
    

}

void Fantasma::pintaAzul(){

    miniwin::color(miniwin::AZUL);

    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 9,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 7,
                                 8);

    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 2,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 5,
                                 MARGEN + this->getPosicion().x * TAM + TAM - 2,
                                 MARGEN + this->getPosicion().y * TAM + TAM - 3);

    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 9,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 16,
                                 2);
    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 4,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 16,
                                 2);
    miniwin::circulo_lleno(      MARGEN + 1 + this->getPosicion().x * TAM + 14,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 16,
                                 2);

    miniwin::color(getColorDecora());

    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 5,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 2,
                                 MARGEN + 1 + this->getPosicion().x * TAM + 7,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 4);

    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 10,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 2,
                                 MARGEN + 1 + this->getPosicion().x * TAM + 12,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 4);
    

}

void Fantasma::pintaBigFantasma(){
    
    miniwin::color(miniwin::AZUL);
    miniwin::circulo_lleno(300,130,30);
    miniwin::rectangulo_lleno(270,130,330,180);
    miniwin::circulo_lleno(280,180,10);
    miniwin::circulo_lleno(300,180,10);
    miniwin::circulo_lleno(320,180,10);
    
    miniwin::color(miniwin::BLANCO);
    miniwin::circulo_lleno(290,120,5);
    miniwin::circulo_lleno(310,120,5);
}