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
    Pacman(int x, int y, int colorSolido, int colorDecora);

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

    static void pintaBigPacman();
};

#endif  //PACMAN_HPP