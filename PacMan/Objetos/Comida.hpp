/**!<Guardas de inclusión*/
#ifndef COMIDA_HPP
#define COMIDA_HPP

/**!<Bibliotecas necesaria*/
#include "Figura.hpp"

/**
 *@class Comida
 *@brief Representa la comida de Pacman
 */
class Comida : public Figura{
public:
    /**
     *@brief Método constructor de Comida
     */
    Comida(/* args */);

    /**
     *@brief Método constructor de Comida
     *
     *@param x Posición en x de la comida
     *
     *@param y Posición en y de la comida
     *
     *@param colorSolido[] Color solido de la comida
     *
     *@param colorDecora[] Color de decoración de la comida
     */
    Comida(int x, int y, int colorSolido[], int colorDecora[]);

    /**
     *@brief Método destructor de Comida
     */
    ~Comida();

    /**
     *@brief Método que pinta una comida pequeña
     */
    void pinta();

    /**
     *@brief Método que pinta una comida grande
     */
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
    miniwin::color_rgb(getColorSolido()[0],
                       getColorSolido()[1],
                       getColorSolido()[2]
    );
    miniwin::rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 6,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 6,
                                 MARGEN + 1 + this->getPosicion().x * TAM + 8,
                                 MARGEN + 1 + this->getPosicion().y * TAM + 8);
}

void Comida::pintaGrande(){
    miniwin::color_rgb(getColorSolido()[0],
                       getColorSolido()[1],
                       getColorSolido()[2]
    );

    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + 7,
                            MARGEN + 1 + this->getPosicion().y * TAM + 6,3);
}

#endif  //COMIDA_HPP