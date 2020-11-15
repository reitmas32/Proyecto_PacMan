#include <objetos/Tablero.hpp>

Tablero::Tablero(int ColorPared, int ColorCamino){
    
    this->ColorPared = ColorPared;
    this->ColorCamino = ColorCamino;
    
    /*Creamos el mapa*/

    /*Definimos las dimensiones*/
    this->Columnas = COLUMNAS;
    this->Filas = FILAS;

    /*Creamos el contenedor del mapa*/
    this->mapa = new uint8_t*[Filas];

<<<<<<< HEAD:PacMan/Objetos/Tablero.hpp
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
    int ColorPared[3];

    /**!<Color del camino del tablero*/
    int ColorCamino[3];

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
     *@brief Método que ve si el pacman murió
     *
     *@param p Pacman del tablero
     *
     *@param f Fantasma que puede comer a pacman
     *
     *@return True si el pacman murió, en caso contrario retorna false
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

Tablero::Tablero(int mapa, int ColorPared[], int ColorCamino[]){
    
    for (size_t i = 0; i < 3; i++){
        this->ColorPared[i] = ColorPared[i];
        this->ColorCamino[i] = ColorCamino[i]; 
=======
    for( size_t i = 0; i < this->Filas; i++){
        this->mapa[i] = new uint8_t[Columnas];
>>>>>>> test:src/objetos/Tablero.cpp
    }

    /*Cargamos el mapa*/
    for(size_t i = 0; i < this->Filas; i++){
        for( size_t j = 0; j < this->Columnas; j++){
            this->mapa[i][j] = Mapa[i][j];
        }
    }

    /*Creamos el tablero*/
    this->tablero = new Cuadro*[Filas]; 
    for( size_t i = 0; i < this->Filas; i++){
        this->tablero[i] = new Cuadro[Columnas]; 
    }
    /*Definimos las vidas y puntos*/
    this->vidas = 3;
    this->puntos = 0;

    /*Creamos el grafo*/
    this -> grafo = new Graph();
}

Tablero::~Tablero()
{
    /*Destruimos el mapa*/
    for(size_t i=0; i<this -> Filas; i++){
        delete this -> mapa[i];
    }
    delete[] mapa;

    /*Destruimos el tablero*/

    for(size_t i=0; i<this -> Filas; i++){
        this -> tablero[i] -> ~Cuadro();
    }

    delete[] tablero;

    /*Eliminamos el grafo*/
    delete grafo;

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
                this->tablero[i][j].setColorSolido(miniwin::CAFE);
                this->tablero[i][j].setColorDecora(miniwin::CAFE);
            break;
            default:
                break;
            }
        }
    }
}

void Tablero::creaGrafo(){

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
        }
   }
}

void Tablero::pinta(){
    miniwin::vredimensiona(this->Columnas * TAM + MARGEN * 2 + TAM*6, this->Filas * TAM + MARGEN * 2);
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
        
        if(this->tablero[figura.getPosicion().y][figura.getPosicion().x].getColorSolido() != this->ColorCamino){
            return true;
        }
        
        return false;
}

void Tablero::repinta(){
    miniwin::borra();
    this->pinta();

    for(size_t i = 0; i < this->vidas ; i++){
        Pacman p_v = Pacman(23,2+i*2,miniwin::AMARILLO,miniwin::NEGRO);
        p_v.pinta_der();
    }
    miniwin::color(miniwin::BLANCO);
    miniwin::texto(23*TAM, 15*TAM, "Puntos:");
    miniwin::texto(23*TAM,16*TAM, intToString(this->puntos));
    miniwin::refresca();
}


std::string Tablero::intToString(int num){
    std::stringstream sout;
    sout << num;
    return sout.str();
}

size_t Tablero::stringToInt(std::string num){
   return stoi(num,nullptr,10);
}



void Tablero::moveFantasma(Fantasma* f,Tablero* T,Pacman* p, int color){

    /*Varibales necesarias*/
    std::string posFantasma = intToString(f->getPosicion().y + f->getPosicion().x * T -> Columnas);
    std::string posPacman = intToString(p->getPosicion().y + p->getPosicion().x * T -> Columnas);
    size_t x =0,y=0;
    size_t posIntFantasma =0;

    /*Obtenemos el mapa del grafo*/
    Map<std::string,Vertex*> *mapa = T -> grafo -> get_map();

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

    if(posFantasma != posPacman){
        Stack<std::string> *s = T -> grafo->goTo(posFantasma, posPacman);



        /*Convertimos a entero*/
        s->Pop();
        posIntFantasma = stringToInt(s ->Pop());

        /*Sacamos las coordenadas*/
        y = posIntFantasma%T -> Columnas;

        x = (posIntFantasma -y)/T -> Columnas;

        size_t y_actual = p->getPosicion().y;
        size_t x_actual = p->getPosicion().x;

        Fantasma f_copia = *f;

        if(x < x_actual ){
            f->mueve_derecha();
        }
        else if(x > x_actual){
            f->mueve_izquierda();
        }
        else if (y < y_actual){
            f->mueve_abajo();
        }
        else if( y > y_actual){
            f->mueve_arriba();
        }
        
        if(T->colision(*f)){
            *f = f_copia;
        }
        f->pinta();
    
    }
}

void Tablero::huyeFantasma(Fantasma* f,Tablero* T,Pacman* p, int color){

    /*Varibales necesarias*/
    std::string posFantasma = intToString(f->getPosicion().y + f->getPosicion().x * T -> Columnas);
    std::string posPacman = intToString(p->getPosicion().y + p->getPosicion().x * T -> Columnas);
    size_t x =0,y=0;
    size_t posIntFantasma =0;

    /*Obtenemos el mapa del grafo*/
    Map<std::string,Vertex*> *mapa = T -> grafo -> get_map();

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

    if(posFantasma != posPacman){
        Stack<std::string> *s = T -> grafo->goTo(posFantasma, posPacman);



        /*Convertimos a entero*/
        s->Pop();
        posIntFantasma = stringToInt(s ->Pop());

        /*Sacamos las coordenadas*/
        y = posIntFantasma%T -> Columnas;

        x = (posIntFantasma -y)/T -> Columnas;

        size_t y_actual = p->getPosicion().y;
        size_t x_actual = p->getPosicion().x;

        Fantasma f_copia = *f;

        if(x > x_actual ){
            f->mueve_derecha();
        }
        else if(x < x_actual){
            f->mueve_izquierda();
        }
        else if (y > y_actual){
            f->mueve_abajo();
        }
        else if( y < y_actual){
            f->mueve_arriba();
        }
        
        if(T->colision(*f)){
            *f = f_copia;
        }
        f->pinta();
    
    }
}