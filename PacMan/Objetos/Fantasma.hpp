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
    Fantasma(int x, int y, int colorSolido, int colorDecora);

    /**
     *@brief Método destructor del Fantasma
     */
    ~Fantasma();

    /** 
     *@brief
     */
    void pinta();

    /** 
     *@brief
     */
    void pintaAzul();

    static void pintaBigFantasma();
};

#endif  //GHOST_HPP
