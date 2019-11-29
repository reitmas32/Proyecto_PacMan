#ifndef CUADRO_CPP
#define CUADRO_CPP
#include "Cuadro.hpp"


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