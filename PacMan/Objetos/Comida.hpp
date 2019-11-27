#ifndef COMIDA_HPP
#define COMIDA_HPP
/**
 * Se utilizara la clase Figura de cual hereda la clase comida
 **/
#include "Figura.hpp"

class Comida : public Figura{
private:
    /* data */
public:
    Comida(/* args */);
    Comida(int x, int y, int colorSolido[], int colorDecora[]);
    ~Comida();

    void pinta();
    void pintaGrande();
};

Comida::Comida(int x, int y, int colorSolido[], int colorDecora[])
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
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 6,
                        MARGEN + 1 + this->getPosicion().y * TAM + 6,
                        MARGEN + 1 + this->getPosicion().x * TAM + 8,
                        MARGEN + 1 + this->getPosicion().y * TAM + 8);
}

void Comida::pintaGrande(){
    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );

    circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + 7,
                    MARGEN + 1 + this->getPosicion().y * TAM + 6,
                    3);
}

#endif  //COMIDA_HPP