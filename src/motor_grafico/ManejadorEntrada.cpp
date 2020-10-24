#include <motor_grafico/ManejadorEntrada.hpp>

ManejadorEntrada::ManejadorEntrada(/* args */)
{
    /*Constructor vacío*/
}

ManejadorEntrada::ManejadorEntrada(float posx_instruccion, float posy_instruccion, float posx_entrada, float posy_entrada, int color_instruccion, int color_entrada){
    /*Inacialización de variables*/
    this->posx_entrada = posx_entrada;
    this->posy_entrada = posy_entrada;
    this->posx_instruccion = posx_instruccion;
    this->posy_instruccion = posy_instruccion;
    this->color_entrada = color_entrada;
    this->color_instruccion = color_instruccion;
}

ManejadorEntrada::~ManejadorEntrada()
{
    /*Destructor vacío*/
}

std::string ManejadorEntrada::obtenerEntrada(const std::string& instruccion, bool numero) const{

    miniwin::color(this->color_entrada);
    miniwin::texto(this->posx_instruccion, this->posy_instruccion, instruccion);
    miniwin::color(color_entrada);
    std::string entrada;

    for (int simbolo = miniwin::tecla(); simbolo != miniwin::RETURN; simbolo = miniwin::tecla()){
        simbolo = filtrar_simbolo_miniwin(simbolo);
        if((simbolo == miniwin::ESCAPE || simbolo == 8) && !entrada.empty()){
            miniwin::borra();
            entrada.pop_back();
            miniwin::color(this->color_instruccion);
            miniwin::texto(this->posx_instruccion, this->posy_instruccion, instruccion);

        }else if(numero && (isdigit(simbolo) || simbolo == this->PUNTO)){
            entrada += simbolo;

        }else if(!numero && (isalnum(simbolo) || simbolo == miniwin::ESPACIO)){
            entrada += simbolo;

        }
        
        miniwin::color(this->color_entrada);
        miniwin::texto(this->posx_entrada,this->posy_entrada,entrada);
        miniwin::refresca();
        miniwin::espera(20);
        
    }
    return entrada;
}

int ManejadorEntrada::filtrar_simbolo_miniwin(int simbolo) const{
    if(simbolo == 190 || simbolo == 188 || simbolo == 110){
        return this->PUNTO;
    }
    if(simbolo >= 96 && simbolo < 105){
        return simbolo - 48;
    }
    return simbolo;
}