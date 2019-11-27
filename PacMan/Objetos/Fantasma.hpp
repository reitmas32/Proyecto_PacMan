#ifndef GHOST_HPP
#define GHOST_HPP

#include <sstream>

#include "../Graphics_Engine/Cuadro.hpp"

#include "Figura.hpp"

#include "../Graphics_Engine/Mapas.hpp"

#include "../../Estructuras/Grafo/Grafo.hpp"

#include "../../Estructuras/DLLTemplate/DLL.hpp"

#include "../../Estructuras/StackTemplate/Stack.hpp"

class Fantasma : public Figura{
private:
    int dir;
    int time;
public:
    Stack<std::string> *roadToPacman;
    Fantasma(/* args */);
    Fantasma(int x, int y, int colorSolido[], int colorDecora[]);
    ~Fantasma();

    void pinta();

    int getDir(){return dir;}
    int getTime(){return time;}

    void setDir(int dir){this->dir = dir;}
    void setTime(int time){this->time = time;}
};

Fantasma::Fantasma(/* args */)
{
}

Fantasma::Fantasma(int x, int y, int colorSolido[], int colorDecora[])
{
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
    this->setDir(0);
    this->setTime(0);
}

Fantasma::~Fantasma()
{
}

void Fantasma::pinta(){

    color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );
    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 3,
                        MARGEN + 1 + this->getPosicion().y * TAM,
                        MARGEN + this->getPosicion().x * TAM + TAM - 3,
                        MARGEN + this->getPosicion().y * TAM + TAM);

    color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 4,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 4,
                        MARGEN + 1 + this->getPosicion().x * TAM + 5,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 1);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 7,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 4,
                        MARGEN + 1 + this->getPosicion().x * TAM + 8,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 1);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 10,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 4,
                        MARGEN + 1 + this->getPosicion().x * TAM + 11,
                        MARGEN + 1 + this->getPosicion().y * TAM + TAM - 1);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 5,
                        MARGEN + 1 + this->getPosicion().y * TAM + 2,
                        MARGEN + 1 + this->getPosicion().x * TAM + 7,
                        MARGEN + 1 + this->getPosicion().y * TAM + 4);

    rectangulo_lleno(   MARGEN + 1 + this->getPosicion().x * TAM + 8,
                        MARGEN + 1 + this->getPosicion().y * TAM + 2,
                        MARGEN + 1 + this->getPosicion().x * TAM + 10,
                        MARGEN + 1 + this->getPosicion().y * TAM + 4);

}


#endif  //GHOST_HPP
