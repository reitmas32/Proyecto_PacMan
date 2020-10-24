/**!<Guardas de inclusión*/
#ifndef COMIDA_HPP
#define COMIDA_HPP

/**!<Bibliotecas necesaria*/
#include <objetos/Figura.hpp>

/**
 *@class Comida
 *@brief Representa la comida de Pacman
 */
class Comida : public Figura{
private:
    /* data */
public:
    /**
     *@brief Método constructor de Comida
     */
    Comida(/* args */);

    /**
     *@brief Método constructor de Comida
     *
     *@param x
     *
     *@param y
     *
     *@param colorSolido[]
     *
     *@param colorDecora[]
     */
    Comida(int x, int y, int colorSolido, int colorDecora);

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

#endif  //COMIDA_HPP