/**!<Guardas de inclusión*/
#ifndef GHOST_HPP
#define GHOST_HPP

/**!<Bibliotecas necesarias*/
#include <sstream>

#include "Figura.hpp"

/**
 *@class Fantasma
 *@brief Representa un fantasma
 */

class Fantasma : public Figura{
private:
    /**!<*/
    int dir;

    /**!<*/
    int time;
public:

    /**
     *@brief Método constructor del Fantasma
     */
    Fantasma(/* args */);

    /**
     *@brief Método constructor del Fantasma
     *
     *@param x
     *
     *@param y
     *
     *@param colorSolido[]
     *
     *@param colorDecora[]
     */
    Fantasma(int x, int y, int colorSolido[], int colorDecora[]);

    /**
     *@brief Método destructor del Fantasma
     */
    ~Fantasma();

    /** 
     *@brief Método que pinta al fantasma
     */
    void pinta();

    /** 
     *@brief Método que pinta al fantasma de azul
     */
    void pintaAzul();

    /**
     *@brief  Método que nos regresa el valor de dir
     */
    int getDir(){return dir;}

    /** 
     *@brief Método que nos regresa el valor de time
     */
    int getTime(){return time;}

    /** 
     *@brief Método que define el valor de dir
     *
     *@param dir Nuevo valor de dir
     */
    void setDir(int dir){this->dir = dir;}

    /**
     *@brief Método que define el valor de time
     *
     *@param time Nuevo valor de time
     */
    void setTime(int time){this->time = time;}

    static void pintaBigFantasma();
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

    miniwin::color_rgb(getColorSolido()[0],
              getColorSolido()[1],
              getColorSolido()[2]
    );

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

    miniwin::color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );

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

    miniwin::color_rgb(getColorDecora()[0],
              getColorDecora()[1],
              getColorDecora()[2]
    );

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

#endif  //GHOST_HPP
