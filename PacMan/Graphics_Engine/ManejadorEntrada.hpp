#ifndef MANEJADOR_ENTRADA_HPP
#define MANEJADOR_ENTRADA_HPP
#include "miniwin.h"

class ManejadorEntrada
{
private:
    float posx_instruccion;
    float posy_instruccion;
    float posx_entrada;
    float posy_entrada;
    int color_instruccion;
    int color_entrada;
    int filtrar_simbolo_miniwin(int simbolo) const;

    enum{
        PUNTO = 46
    };

public:
    ManejadorEntrada(/* args */);
    ManejadorEntrada(float posx_instruccion, float posy_instruccion, float posx_entrada, float posy_entrada, int color_instruccion, int color_entrada);
    ~ManejadorEntrada();
    std::string obtenerEntrada(const std::string& instruccion, bool numero) const;
};

#endif  //MANEJADOR_ENTRADA_HPP
