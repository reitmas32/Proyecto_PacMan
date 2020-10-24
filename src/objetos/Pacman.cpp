#include <objetos/Pacman.hpp>

Pacman::Pacman(/* args */)
{
}

Pacman::~Pacman()
{
}

Pacman::Pacman(int x, int y, int colorSolido, int colorDecora){
    this->setPosicion(x,y);
    this->setColorSolido(colorSolido);
    this->setColorDecora(colorDecora);
}

void Pacman::pinta_der(){
    miniwin::color(getColorSolido());
    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                             RADIO);

    miniwin::color(getColorDecora());

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 6,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 7,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 7,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 9,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5);

    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                             2);

}

void Pacman::pinta_izq(){
    miniwin::color(getColorSolido());
    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                             RADIO);

    miniwin::color(getColorDecora());

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 1);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 1);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 6,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 7,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 7,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 10,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5);

    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                             2);
}

void Pacman::pinta_arri(){
    miniwin::color(getColorSolido());
    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                             RADIO);

    miniwin::color(getColorDecora());

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 6,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 7,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 7,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 10);

    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
                             2);
    

}

void Pacman::pinta_abajo(){
    miniwin::color(getColorSolido());
    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO,
                             RADIO);

    miniwin::color(getColorDecora());

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 1,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 2,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 6,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 4,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 7,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO - 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::linea(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 7,
                     MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 5,
                     MARGEN + 1 + this->getPosicion().y * TAM + RADIO + 10);

    miniwin::circulo_lleno(  MARGEN + 1 + this->getPosicion().x * TAM + RADIO + 3,
                             MARGEN + 1 + this->getPosicion().y * TAM + RADIO - 3,
                             2);
    


}

void Pacman::pintaBigPacman(){
    miniwin::color(miniwin::AMARILLO);
    miniwin::circulo_lleno(  150,140,45);

    miniwin::color(miniwin::NEGRO);

    miniwin::rectangulo_lleno(  160,138,240,142);
    miniwin::rectangulo_lleno(  163,142,240,146);
    miniwin::rectangulo_lleno(  163,133,240,138);
    miniwin::rectangulo_lleno(  166,146,240,150);
    miniwin::rectangulo_lleno(  166,128,240,133);
    miniwin::rectangulo_lleno(  169,150,240,154);
    miniwin::rectangulo_lleno(  169,123,240,128);
    miniwin::rectangulo_lleno(  172,154,240,158);
    miniwin::rectangulo_lleno(  172,118,240,123);
    miniwin::rectangulo_lleno(  175,158,240,162);
    miniwin::rectangulo_lleno(  175,113,240,118);
    miniwin::rectangulo_lleno(  178,162,240,167);
    miniwin::rectangulo_lleno(  178,108,240,113);

    miniwin::circulo_lleno(133,120,7);

}