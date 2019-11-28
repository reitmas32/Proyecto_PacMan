/**!<Guardas de inclusión*/
#ifndef TABLERO_HPP
#define TABLERO_HPP

/**!<Bibliotecas necesarias*/
#include <vector>

#include <iostream>

#include <sstream>

#include "Pacman.hpp"

#include "Fantasma.hpp"

#include "../Graphics_Engine/Mapas.hpp"

#include "../../Estructuras/Grafo/Grafo.hpp"

#include <fstream>


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

    /**!<*/
    size_t Columnas;

    /**!<*/
    size_t Filas;

    /**!<*/
    uint8_t** mapa;

    /**!<*/
    Cuadro** tablero;

    /**!<*/
    size_t vidas;

    /**!<*/
    int ColorPared[3];

    /**!<*/
    int ColorCamino[3];

    /**!<*/
    size_t puntos;

    /**!<*/
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
     */
    Tablero();

    /**
     *@brief Método constructor del Tablero
     *
     *@param mapa
     *
     *@pram ColorPared[]
     *
     *@param ColorCamino[]
     */
    Tablero(int mapa, int ColorPared[], int ColorCamino[]);

    /** 
     *@brief Método destructor del Tablero
     */
    ~Tablero();

    /**
     *@brief
     */
    void creaMundo();

    /**
     *@brief Método que crea el camino por el cual pueden caminar los fantasmas y pacman
     */
    void creaGrafo();

    /**
     *@brief
     */
    void pinta();

    /**
     *@brief
     */
    bool colision(Figura figura);

    /**
     *@brief
     */
    void repinta();

    /**
     *@brief
     */
    bool deadPacman(Pacman p, Fantasma* f);

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
    static void moveFantasma(Fantasma* f,Tablero T,Pacman* p, int color);
};

Tablero::Tablero(/* args */)
{

}

Tablero::Tablero(int mapa, int ColorPared[], int ColorCamino[]){
    
    for (size_t i = 0; i < 3; i++){
        this->ColorPared[i] = ColorPared[i];
        this->ColorCamino[i] = ColorCamino[i]; 
    }
    
    /*Creamo el mapa*/
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
#if 0
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
#endif

    /*Los conectamos horizontalmente*/
   for(size_t i=0; i<this -> Filas; i++){
        for(size_t j =0; j<this -> Columnas; j++){

            if(this->mapa[i][j] == 0 || this->mapa[i][j] == 3){
                if(this->mapa[i][j-1] == 0 || this->mapa[i][j-1] == 3){
                    this->grafo->add_edge(intToString(i+j*this->Columnas), intToString(i+(j-1)*this->Columnas));
                }
                if(this->mapa[i][j+1] == 0 || this->mapa[i][j+1] == 3){
                    this->grafo->add_edge(intToString(i+j*this->Columnas), intToString(i+(j+1)*this->Columnas));
                }

                if(this->mapa[i-1][j] == 0 || this->mapa[i-1][j] == 3){
                    this->grafo->add_edge(intToString(i+j*this->Columnas), intToString((i-1)+j*this->Columnas));
                }
                if(this->mapa[i+1][j] == 0 || this->mapa[i+1][j] == 3){
                    this->grafo->add_edge(intToString(i+j*this->Columnas), intToString((i+1)+j*this->Columnas));
                }
            }
/*
            if(this -> mapa[i][j] == 0 && this -> mapa[i][j-1] == 0){
                grafo -> add_edge(intToString(i+(j-1)*this ->Columnas),intToString(i+j*this -> Columnas));
            }

            if(this -> mapa[i][j] == 0 && this -> mapa[i][j-1] == 3){
                grafo -> add_edge(intToString(i+(j-1)*this -> Columnas),intToString(i+j*this -> Columnas));
            }
*/
        }
    }

    /*Los conectamos verticalmente*/
#if 0
    for(size_t i=0; i<this -> Filas; i++){
        for(size_t j =0; j<this -> Columnas; j++){

            if(this->mapa[i][j] == 0 || this->mapa[i][j] == 3){
                if(this->mapa[i-1][j] == 0 || this->mapa[i-1][j] == 3){
                    this->grafo->add_edge(intToString(i+j*this->Columnas), intToString((i-1)+j*this->Columnas));
                }
                if(this->mapa[i+1][j] == 0 || this->mapa[i+1][j] == 3){
                    this->grafo->add_edge(intToString(i+j*this->Columnas), intToString((i+1)+j*this->Columnas));
                }
            }      

/*
            if(this -> mapa[i][j] == 0 && this -> mapa[i-1][j] == 0){
                grafo -> add_edge(intToString((i-1)+j*this -> Columnas),intToString(i+j*this -> Columnas));
            }

            if(this -> mapa[i][j] == 0 && this -> mapa[i-1][j] == 3){
                grafo -> add_edge(intToString((i-1)+j*this -> Columnas),intToString(i+j*this -> Columnas));
            }
*/
       }
    }
#endif
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


std::string Tablero::intToString(int num){
    std::stringstream sout;
    sout << num;
    return sout.str();
}

/**
 *@brief Función que convierte una string a un int
 *
 *@param num String que se convertira a int
 *
 *@return la string convertida a int
 */
size_t Tablero::stringToInt(std::string num){
   return stoi(num,nullptr,10);
}



void Tablero::moveFantasma(Fantasma* f,Tablero T,Pacman* p, int color){

    /*Varibales necesarias*/
    std::string posFantasma = intToString(f->getPosicion().y + f->getPosicion().x * T.Columnas);
    std::string posPacman = intToString(p->getPosicion().y + p->getPosicion().x * T.Columnas);
    size_t x =0,y=0;
    size_t posIntFantasma =0;

    /*Obtenemos el mapa del grafo*/
    Map<std::string,Vertex*> *mapa = T.grafo -> get_map();

    /*Buscamos al pacman*/

    mapa -> search(posPacman);

    /*obtenemos a la couple que contiene al pacman*/

    Couple<std::string,Vertex*> *couplePacman = mapa -> getCursor();

    /*Obtenemos al vertex de pacman*/

    Vertex *pacman = couplePacman ->getValue();

    /*Obtenemos a los vecinos de pacman*/

    DLL<Vertex*>* vecinos = pacman -> get_neighbors();

    /*Vertex temporal para recibir la información*/
    Vertex *tmp;

    /*Dependiendo el fantasma le daremos uan posición de pacman*/

    switch(color){
        case 0:
            /*Le damos la posición exacta*/
            break;
        case 1: 
            vecinos -> CursorFirst();
            vecinos -> Peek(&tmp);
            posPacman = tmp -> get_name();
            break;
        case 2:
            vecinos -> CursorLast();
            vecinos -> Peek(&tmp);
            posPacman = tmp -> get_name();
            break;
    }

    //std::cout << std::endl <<"Paso el case" <<std::endl;
    if(posFantasma != posPacman){
        Stack<std::string> *s = T.grafo->goTo(posFantasma, posPacman);

        //std::cout<<posFantasma<<" "<<posPacman<<std::endl;

        //T.grafo ->print();
        //while (s ->Len() > 5 && !s ->IsEmpty())
        //{
            /*Convertimos a entero*/
            s->Pop();
            posIntFantasma = stringToInt(s ->Pop());

            /*Sacamos las coordenadas*/
            y = posIntFantasma%T.Columnas;

            x = (posIntFantasma -y)/T.Columnas;

            /*Verificamos que sea una posición valida*/      
            if(T.mapa[y][x] != 2 && T.mapa[y][x] != 1){
                f ->setPosicion(x,y);
            }
            

            //std::cout<< posIntFantasma << " -> x: " << x << " y: " << y <<std::endl;
        //}  
        //std::cout << std::endl <<"Paso el while" <<std::endl;       
    }
}


#endif  //TABLERO_HPP
