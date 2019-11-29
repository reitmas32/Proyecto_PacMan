#ifndef COLOR_HPP
#define COLOR_HPP

/**
 * Se utilizara la estructura vector para almacenar los valores de los colores
 **/
#include <vector>

/**
 * Namespace que almacena los colores del Motor Grafico
 **/
namespace Colors
{
    int Red[]                    = {255,   0,   0};
    int Blue[]                   = {  0,   0, 255};
    int Green[]                  = {  0, 255,   0};  
    int Yellow[]                 = {255, 255,   0};  
    int Magenta[]                = {255,   0, 255};  
    int Cyan[]                   = {  0, 255, 255};  
    int White[]                  = {255, 255, 255};  
    int Black[]                  = {  0,   0,   0};  
    int Brown[]                  = {101,  67,  33};  
    int Gray[]                   = {153, 153, 153};

    bool cmpColor(int color1[], int color2[]){
        bool equal = true;
        for (size_t i = 0; i < 3; i++)
        {
            if(color1[i] != color2[i]){
                equal = false;
                break;
            }
        }
        return equal;
    }

    void equalTo(int color1[], int color2[]){
        for (size_t i = 0; i < 3; i++)
        {
            color1[i] = color2[i];
        }
    }
} // namespace Colors

#endif  //COLORS_HPP