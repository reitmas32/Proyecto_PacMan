#ifndef TABLERO_HPP
#define TABLERO_HPP

#include <vector>

#include <iostream>

#include <sstream>

#include "Pacman.hpp"

#include "Fantasma.hpp"

#include "../Graphics_Engine/Mapas.hpp"

#include "../../Estructuras/Grafo/Grafo.hpp"

#include <fstream>

//Convierte de int a string
std::string intToString(int num){
    std::stringstream sout;
    sout << num;
    return sout.str();
}

bool cmpString(std::string val1, std::string val2){
    return val1 == val2;
}

class Tablero
{
public:
    
    int posPacman;
    int posFantasma;

    size_t Columnas;
    size_t Filas;
    uint8_t** mapa;
    Cuadro** tablero;
    size_t vidas;
    int ColorPared[3];
    int ColorCamino[3];
    size_t puntos;
    Graph* grafo;
public:
    Tablero();
    Tablero(int mapa, int ColorPared[], int ColorCamino[]);
    ~Tablero();

    void creaMundo();

    void creaGrafo();

    void pinta();

    bool colision(Figura figura);

    void repinta();

    bool deadPacman(Pacman p, Fantasma* f);
};

Tablero::Tablero(/* args */)
{

}

Tablero::Tablero(int mapa, int ColorPared[], int ColorCamino[]){
    
    for (size_t i = 0; i < 3; i++){
        this->ColorPared[i] = ColorPared[i];
        this->ColorCamino[i] = ColorCamino[i]; 
    }
    
    switch (mapa)
    {
    case MAPAS::LevelOne:
        this->Columnas = MAPAS::LevelOneWorld::COLUMNAS;
        this->Filas = MAPAS::LevelOneWorld::FILAS;
        this->mapa = (uint8_t**)calloc(this->Filas, sizeof(uint8_t*));
        for( size_t i = 0; i < this->Filas; i++){
            this->mapa[i] = (uint8_t*)calloc(this->Columnas, sizeof(uint8_t));
        }
        for(size_t i = 0; i < this->Filas; i++){
            for( size_t j = 0; j < this->Columnas; j++){
                this->mapa[i][j] = MAPAS::LevelOneWorld::Mapa[i][j];
            }
        }
        this->tablero = (Cuadro**)calloc(this->Filas, sizeof(Cuadro*));
        for( size_t i = 0; i < this->Filas; i++){
            this->tablero[i] = (Cuadro*)calloc(this->Columnas, sizeof(Cuadro));
        }
        break;
    
    default:
        break;
    }
    this->vidas = 3;
    this->puntos = 0;
}

Tablero::~Tablero()
{
    //this->LevelOneGraph.~Graph();
}

void Tablero::creaMundo(){

    for(size_t i = 0; i < this->Filas; i++){
        for(size_t j = 0; j < this->Columnas; j++){
            switch (this->mapa[i][j])
            {
            case 0:
            case 3:
                this->tablero[i][j].setPosicion(j,i);
                this->tablero[i][j].setColorSolido(this->ColorCamino);
                this->tablero[i][j].setColorDecora(this->ColorCamino);
            break;
            case 1:
                this->tablero[i][j].setPosicion(j,i);
                this->tablero[i][j].setColorSolido(this->ColorPared);
                this->tablero[i][j].setColorDecora(this->ColorPared);
            break;
            case 2:
                this->tablero[i][j].setPosicion(j,i);
                this->tablero[i][j].setColorSolido(Colors::Brown);
                this->tablero[i][j].setColorDecora(Colors::Brown);
            break;
            default:
                break;
            }
        }
    }
}

void Tablero::creaGrafo(){
    this -> grafo = new Graph();
        /*Creamos los vertices*/
        for(size_t i = 0; i<this ->Filas; i++){
            for(size_t j=0; j<this ->Columnas; j++){
                if(this -> mapa[i][j] == 0 || this -> mapa[i][j] == 3)
                    grafo -> add_vertex(new Vertex(intToString(i+j*this -> Columnas)));
            }
        }

        /*Los conectamos horizontalmente*/
        for(size_t i=0; i<this -> Filas; i++){
            for(size_t j =0; j<this -> Columnas; j++){
                if(this -> mapa[i][j] == 0 && this -> mapa[i][j-1] == 0){
                    grafo -> add_edge(intToString(i+(j-1)*this ->Columnas),intToString(i+j*this -> Columnas));
                }

                if(this -> mapa[i][j] == 0 && this -> mapa[i][j-1] == 3){
                    grafo -> add_edge(intToString(i+(j-1)*this -> Columnas),intToString(i+j*this -> Columnas));
                }
            }
        }

        /*Los conectamos verticalmente*/
        for(size_t i=0; i<this -> Filas; i++){
            for(size_t j =0; j<this -> Columnas; j++){
                if(this -> mapa[i][j] == 0 && this -> mapa[i-1][j] == 0){
                    grafo -> add_edge(intToString((i-1)+j*this -> Columnas),intToString(i+j*this -> Columnas));
                }

                if(this -> mapa[i][j] == 0 && this -> mapa[i-1][j] == 3){
                    grafo -> add_edge(intToString((i-1)+j*this -> Columnas),intToString(i+j*this -> Columnas));
                }
            }
        }
}

void Tablero::pinta(){
    vredimensiona(this->Columnas * TAM + MARGEN * 2 + TAM*6, this->Filas * TAM + MARGEN * 2);
    for(size_t i = 0; i < this->Filas; i++){
        for(size_t j = 0; j < this->Columnas; j++){
            this->tablero[i][j].pintaSolido();
        }
    }
}

bool Tablero::colision(Figura figura){

        if(figura.getPosicion().x < 0 || figura.getPosicion().x >= (int)this->Columnas){
            return true;
        }
        if(figura.getPosicion().y < 0 || figura.getPosicion().y >= (int)this->Filas){
            return true;
        }
        
        if(!Colors::cmpColor(this->tablero[figura.getPosicion().y][figura.getPosicion().x].getColorSolido(), this->ColorCamino)){
            return true;
        }
        
        return false;
}

void Tablero::repinta(){
    borra();
    this->pinta();

    for(size_t i = 0; i < this->vidas ; i++){
        Pacman p_v = Pacman(23,2+i*2,Colors::Yellow,Colors::Black);
        p_v.pinta_der();
    }
    color(BLANCO);
    texto(23*TAM, 10*TAM, "Puntos:");
    texto(23*TAM,11*TAM, intToString(this->puntos));
    refresca();
}


#endif  //TABLERO_HPP
