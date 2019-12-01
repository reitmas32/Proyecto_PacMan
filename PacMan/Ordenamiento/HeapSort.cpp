#include "HeapSort.hpp"

void print( std::vector<Jugador> jugadores, int tam){
    for(int i = 0; i<tam; i++){
		std::cout<<"Nombre: "<<jugadores[i].name<<", puntaje: "<<jugadores[i].value<<std::endl;
	}
}

void printWindow( std::vector<Jugador> jugadores, int tam){
    miniwin::color(miniwin::BLANCO);
    for(int i = 0; i<tam; i++){
		std::string text = "";
        text += "#" + Tablero::intToString(i + 1)+ " " + jugadores[i].name + " : " + Tablero::intToString(jugadores[i].value);
        miniwin::texto(60,30 + i*TAM, text);
        if( i == 9 ) break;
	}
    miniwin::refresca();
}

void swap(Jugador* num1, Jugador* num2){
    Jugador temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void heapify_max(std::vector<Jugador> jugadores, int tam, int k) 
{
    int largest=k;
    int left = 2*k + 1;  
    int right = 2*k + 2; 
  
    /*Si el hijo izquierdo es mas grande que la raíz*/
    if (left < tam && jugadores[left] > jugadores[largest]) 
        largest = left; 
  
    /*Si el hijo derecho es mas grande que el más grande hasta ahora*/
    if (right < tam && jugadores[right] > jugadores[largest]) 
        largest = right; 

    /*Si el más grande no es la raíz*/
    if (largest != k) 
    { 
        swap(&jugadores[k], &jugadores[largest]); 
  
        heapify_max(jugadores, k, largest); 
    } 
}

void heapify_min(std::vector<Jugador> jugadores, int tam, int k) 
{ 
    int smallest=k;
    int left = 2*k + 1; 
    int right = 2*k + 2; 
  
    /*Si el hijo izquierdo es mas pequeño que la raíz*/
    if (left < tam && jugadores[left] < jugadores[smallest]) 
        smallest = left; 
  
    /*Si el hijo derecho es mas pequeño que el más pequeño hasta ahora*/
    if (right < tam && jugadores[right] < jugadores[smallest]) 
        smallest = right; 

    /*Si el más pequeño no es la raíz*/
    if (smallest != k) 
    { 
        swap(&jugadores[k], &jugadores[smallest]); 
  
        heapify_min(jugadores, k, smallest); 
    } 
}

void build_max_heap(std::vector<Jugador> jugadores, int tam){
    for (int i = tam / 2 - 1; i >= 0; i--) 
        heapify_max(jugadores, tam, i); 
}

void build_min_heap(std::vector<Jugador> jugadores, int tam){
    for (int i = tam / 2 - 1; i >= 0; i--) 
        heapify_min(jugadores, tam, i); 
}

void Heap_Sort(std::vector<Jugador> jugadores, int tam, int direction){

    if(direction == ASCENDENTE){
        build_max_heap(jugadores, tam);
        for (int i=tam-1; i>=0; i--) 
        { 
            /*Mover la raíz actual al final*/
            swap(&jugadores[0], &jugadores[i]); 

            /*Invocar heapify max en el monticulo reducido*/
            heapify_max(jugadores, i, 0); 
        }
    }
    else{
        build_min_heap(jugadores, tam);
        for (int i=tam-1; i>=0; i--) 
        { 
            /*Mover la raíz actual al final*/
            swap(&jugadores[0], &jugadores[i]); 

            /*Invocar heapify min en el monticulo reducido*/
            heapify_min(jugadores, i, 0); 
        }
    }
}