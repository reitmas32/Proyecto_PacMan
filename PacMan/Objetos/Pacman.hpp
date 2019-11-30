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
     *@param x Posción en x de pacman
     *
     *@param y Posición en y de pacman
     *
     *@param colorSolido Color solido del pacman
     *
     *@param colorDecora Colro de decoración del pacman
     */
    Pacman(int x, int y, int colorSolido, int colorDecora);

    /**
     *@brief Método destructor de Pacman
     */
    ~Pacman();

    /**
     *@brief Método que pinta el pacman viendo hacia la derecha
     */
    void pinta_der();

   /**
     *@brief Método que pinta al pacman viendo hacia la izquierda
     */
    void pinta_izq();

    /**
     *@brief Método que pinta al pacman viendo hacia arriba
     */
    void pinta_arri();

   /**
     *@brief Método que pinta al pacman viendo hacia abajo
     */
    void pinta_abajo();

    /**
     *@brief Método que pinta un pacman grande
     */
    static void pintaBigPacman();
};

#endif  //PACMAN_HPP