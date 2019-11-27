/**!<Guardas de inclusión*/
#ifndef PACMAN_HPP
#define PACMAN_HPP

/**!<Bibliotecas necesaria*/
#include "Figura.hpp"

/**!<Constante*/
const int RADIO = TAM / 2; 


/**
 *@class Pacman
 *brief Representa la Pacman del juego
 */
class Pacman : public Figura
{
public:
    /**
     *@brief Método constructor de Pacman
     */
    Pacman(/* args */);

    /**
     *@brief Metodo constructor de Pacman
     *
     *@param x 
     *
     *@param y
     *
     *@param colorSolido[]
     *
     *@param colorDecora[]
     */
    Pacman(int x, int y, int colorSolido[], int colorDecora[]);

    /**
     *@brief Método destructor de Pacman
     */
    ~Pacman();

    /**
     *@brief
     */
    void pinta_der();

    /**
     *@brief
     */
    void pinta_izq();

    /**
     *@brief
     */
    void pinta_arri();

    /**
     *@brief
     */
    void pinta_abajo();
};

Pacman::Pacman(/* args */)
{
}

Pacman::~Pacman()
{
}

Pacman::Pacman(int x, int y, int colorSolido[], int colorDecora[]){
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

void Pacman::pinta_der(){
    color_rgb(this->getColorSolido()[0],
              this->getColorSolido()[1],
              this->getColorSolido()[2]
    );
    circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                    MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                    RADIO);

    color_rgb(this->getColorDecora()[0],
              this->getColorDecora()[1],
              this->getColorDecora()[2]
    );

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3);
    

}

void Pacman::pinta_izq(){
    color_rgb(this->getColorSolido()[0],
              this->getColorSolido()[1],
              this->getColorSolido()[2]
    );
    circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                    MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                    RADIO);

    color_rgb(this->getColorDecora()[0],
              this->getColorDecora()[1],
              this->getColorDecora()[2]
    );

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 7,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 7,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3);
    

}

void Pacman::pinta_arri(){
    color_rgb(this->getColorSolido()[0],
              this->getColorSolido()[1],
              this->getColorSolido()[2]
    );
    circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                    MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                    RADIO);

    color_rgb(this->getColorDecora()[0],
              this->getColorDecora()[1],
              this->getColorDecora()[2]
    );

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 7);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 7);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6);
    

}

void Pacman::pinta_abajo(){
    color_rgb(this->getColorSolido()[0],
              this->getColorSolido()[1],
              this->getColorSolido()[2]
    );
    circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                    MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                    RADIO);

    color_rgb(this->getColorDecora()[0],
              this->getColorDecora()[1],
              this->getColorDecora()[2]
    );

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 7);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 7);

    linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5,
            MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
            MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6);
    

}

#endif  //PACMAN_HPP