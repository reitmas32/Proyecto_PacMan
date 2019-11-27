#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "Figura.hpp"

//#include "Tablero.hpp"

const int RADIO = TAM / 2; 

class Pacman : public Figura
{
private:
public:
    Pacman(/* args */);
    Pacman(int x, int y, int colorSolido[], int colorDecora[]);
    ~Pacman();
    void pinta_der();
    void pinta_izq();
    void pinta_arri();
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