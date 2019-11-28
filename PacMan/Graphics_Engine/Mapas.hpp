#ifndef MAPAS_HPP
#define MAPAS_HPP

namespace MAPAS
{
    const int NUM_MAPS = 1;
    enum{LevelOne};

    //Mapa principal
    namespace LevelOneWorld{

        //El numero 0 es pordonde se puede caminar
        //El numero 1 son las paredes
        //El numero 2 es la barrera del mundo
        //El numero 3 es la ubucacion de las pildoras
        //El numero 4 es donde inician los fantasmas
        //El numero 5 es donde inicia pacman

        const size_t COLUMNAS = 19;
        const size_t FILAS = 23;
        const size_t NUM_FANTASMAS = 3;
        const size_t NUM_PILDORAS = 4;
        const size_t NUM_VIDAS = 1;
        const int POS_PACMAN_ORIG_X = 9;
        const int POS_PACMAN_ORIG_Y = 18;
        const int POS_FANTASMA_ROJO_ORIG_X = 9;
        const int POS_FANTASMA_ROJO_ORIG_Y = 10;
        const int POS_FANTASMA_VERDE_ORIG_X = 6;
        const int POS_FANTASMA_VERDE_ORIG_Y = 10;
        const int POS_FANTASMA_MAGENTA_ORIG_X = 12;
        const int POS_FANTASMA_MAGENTA_ORIG_Y = 10;
        const int MAX_PUNTAJE = 182;

        uint8_t Mapa[FILAS][COLUMNAS] = {
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
            {2,1,0,1,1,0,0,0,1,0,1,0,0,0,1,1,0,1,2},
            {2,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,2},
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


    }

} // namespace MAPAS

#endif  //MAPAS_HPP

