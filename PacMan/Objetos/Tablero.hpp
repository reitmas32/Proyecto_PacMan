/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

/**!<Bibliotecas necesarias*/
#include <vector>

#include <iostream>

#include <sstream>

#include "Pacman.hpp"

#include "Fantasma.hpp"

#include "../Estructuras/Grafo/Grafo.hpp"

const size_t COLUMNAS = 19;
const size_t FILAS = 23;
const size_t NUM_FANTASMAS = 5;
const size_t NUM_PILDORAS = 4;
const size_t NUM_VIDAS = 1;
const int POS_PACMAN_ORIG_X = 9;
const int POS_PACMAN_ORIG_Y = 18;
const int POS_FANTASMA_ROJO_ORIG_X = 9;
const int POS_FANTASMA_ROJO_ORIG_Y = 8;
const int POS_FANTASMA_VERDE_ORIG_X = 6;
const int POS_FANTASMA_VERDE_ORIG_Y = 10;
const int POS_FANTASMA_MAGENTA_ORIG_X = 12;
const int POS_FANTASMA_MAGENTA_ORIG_Y = 10;
const int POS_FANTASMA_CYAN_ORIG_X = 14;
const int POS_FANTASMA_CYAN_ORIG_Y = 16;
const int POS_FANTASMA_WHITE_ORIG_X = 7;
const int POS_FANTASMA_WHITE_ORIG_Y = 16;
const int MAX_PUNTAJE = 185;

const uint8_t Mapa[FILAS][COLUMNAS] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,2},
    {2,1,0,1,1,0,1,1,0,1,0,1,1,0,1,1,0,1,2},
    {2,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2},
    {2,1,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0,1,2},
    {2,1,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,1,2},
    {2,1,0,1,1,0,1,1,0,0,0,1,1,0,1,1,0,1,2},
    {2,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,2},
    {2,1,0,1,1,0,1,0,1,0,1,0,1,3,1,1,0,1,2},
    {2,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,0,1,2},
    {2,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,2},
    {2,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,2},
    {2,1,0,1,1,0,1,0,1,1,1,0,1,0,1,1,0,1,2},
    {2,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,2},
    {2,1,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0,1,2},
    {2,1,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2},
    {2,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,2},
    {2,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,2},
    {2,1,1,0,0,1,0,1,1,1,1,1,0,1,0,0,1,1,2},
    {2,1,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,1,2},
    {2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

/**
 *@class Tablero
 *@brief Tablero del juego de pacman
 */
class Tablero
{
public:
    /**!<*/
    int posPacman;

    /**!<*/
    int posFantasma;

    /**!<Columnas del tablero*/
    size_t Columnas;

    /**!<Filas del tablero*/
    size_t Filas;

    /**!<Matriz que contiene el mapa del tablero*/
    uint8_t** mapa;

    /**!<Matriz que contiene al mapa para pintarlo en pantallas*/
    Cuadro** tablero;

    /**!<Numero de vidas de pacman*/
    size_t vidas;

    /**!<Color de la pared del tablero*/
    int ColorPared;

    /**!<Color del camino del tablero*/
    int ColorCamino;

    /**!<Numero de puntos obtenidos*/
    size_t puntos;

    /**!<Camino por el cual pueden andar los fantasmas y pacman*/
    Graph* grafo;

    /**
     *@brief Función que convierte una string a un int
     *
     *@param num String que se convertira a int
     *
     *@return la string convertida a int
     */
    static size_t stringToInt(std::string num);

    /**
     *@brief Función que convierte un int a string
     *
     *@param num Int que se convertira a string
     *
     *@return el int convertido a string
     */
    static std::string intToString(int num);

public:
    /**
     *@brief Método constructor del Tablero
     *
     *@param mapa
     *
     *@pram ColorPared
     *
     *@param ColorCamino
     */
    Tablero(int ColorPared, int ColorCamino);

    /** 
     *@brief Método destructor del Tablero
     */
    ~Tablero();

    /**
     *@brief Método que crea el mundo en cual se jugara
     */
    void creaMundo();

    /**
     *@brief Método que crea el camino por el cual pueden caminar los fantasmas y pacman
     */
    void creaGrafo();

    /**
     *@brief Método que pinta al tablero
     */
    void pinta();

    /**
     *@brief Método que checa las colisiones del juego
     *
     *@param Figura figura a la cual se checara si hay colisión
     *
     *@return True si hay una colisción, en caso contrario retorna false
     */
    bool colision(Figura figura);

    /**
     *@brief Método que repinta el tablero
     */
    void repinta();

    /**
     *@brief Función que mueve a lso fantasmas
     *
     *@param f Fantasma que se movera
     *
     *@param T Tablero de juego
     *
     *@param p Pacman del tablero
     *
     *@param color Color del Fantasma
     */
    static void moveFantasma(Fantasma* f,Tablero* T,Pacman* p, int color);

    /**
     *@brief Función que mueve a lso fantasmas lejs de pacman
     *
     *@param f Fantasma que se movera
     *
     *@param T Tablero de juego
     *
     *@param p Pacman del tablero
     *
     *@param color Color del Fantasma
     */
    static void huyeFantasma(Fantasma* f,Tablero* T,Pacman* p, int color);
};

#endif  //TABLERO_HPP
