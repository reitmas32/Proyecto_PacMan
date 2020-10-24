/**!<Guardas de inclusión*/
#ifndef MANEJADOR_ENTRADA_HPP
#define MANEJADOR_ENTRADA_HPP

/**!<Biblioteca necesaria*/
#include <motor_grafico/miniwin.hpp>

/**
 *@class ManejadorEntrada
 *@brief Manejara la entrada del nombre del jugador para guardar su score
 */
class ManejadorEntrada
{
private:
    /**!<Posición en x de la instrucción a mostrar*/
    float posx_instruccion;

    /**!<Posición en y de la instrucción a mostrar*/
    float posy_instruccion;

    /**!<Posición en x de la entrada a recibir*/
    float posx_entrada;

    /**!<Posición en y de la entrada a recibir*/
    float posy_entrada;

    /**!<Color con el que se mostrara la instrucción*/
    int color_instruccion;

    /**!<Color con el que se mostrara la entrada*/
    int color_entrada;

    /**
     *@brief Método que devuelve la tecla que se presiono
     *
     *@param simbolo Tecla presionada
     */
    int filtrar_simbolo_miniwin(int simbolo) const;

    /**!<Valor ASCII del punto*/
    enum{
        PUNTO = 46
    };

public:
    /**
     *@brief Método cosntructor de ManejadorEntrada
     */
    ManejadorEntrada(/* args */);

    /**
     *@brief Método constructor de ManejadorEntrada
     *
     *@param posx_instruccion Posición en x de la instrucción a mostrar
     *
     *@param posy_instruccion Posición en y de la instrucción a mostrar
     *
     *@param posx_entrada Posición en x de la entrada
     *
     *@param posy_entrada Posición en y de la entrada
     *
     *@param color_instruccion Color que tendra la instrucción a mostrar
     *
     *qparam color_entrada Color que tendra la entrada
     */
    ManejadorEntrada(float posx_instruccion, float posy_instruccion, float posx_entrada, float posy_entrada, int color_instruccion, int color_entrada);

    /**
     *@brief Método destructor de ManejadorEntrada
     */
    ~ManejadorEntrada();

    /**
     *@brief Método quje obtiene la entrada ingresada en la pantalla
     *
     *@param instruccion Instrucción mostrada en pantalla
     *
     *@param numero Variable que indica si quieres detectar números o no
     *
     *@return Una cadena con los datos obtenidos
     */
    std::string obtenerEntrada(const std::string& instruccion, bool numero) const;
};

#endif  //MANEJADOR_ENTRADA_HPP
