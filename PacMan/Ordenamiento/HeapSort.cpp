#include "HeapSort.hpp"

void print( Jugador jugadores[], int tam){
    for(int i = 0; i<tam; i++){
		std::cout<<"Nombre: "<<jugadores[i].name<<", puntaje: "<<jugadores[i].value<<std::endl;
	}
}

void swap(Jugador* num1, Jugador* num2){
    Jugador temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void heapify_max(Jugador jugadores[], int tam, int k) 
{
    int largest=k;
    int left = 2*k + 1; // left = 2*i + 1 
    int right = 2*k + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (left < tam && jugadores[left] > jugadores[largest]) 
        largest = left; 
  
    // If right child is larger than largest so far 
    if (right < tam && jugadores[right] > jugadores[largest]) 
        largest = right; 

    // If largest is not root 
    if (largest != k) 
    { 
        swap(&jugadores[k], &jugadores[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify_max(jugadores, k, largest); 
    } 
}

void heapify_min(Jugador jugadores[], int tam, int k) 
{ 
    int smallest=k;
    int left = 2*k + 1; // left = 2*i + 1 
    int right = 2*k + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (left < tam && jugadores[left] < jugadores[smallest]) 
        smallest = left; 
  
    // If right child is larger than largest so far 
    if (right < tam && jugadores[right] < jugadores[smallest]) 
        smallest = right; 

    // If largest is not root 
    if (smallest != k) 
    { 
        swap(&jugadores[k], &jugadores[smallest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify_min(jugadores, k, smallest); 
    } 
}

void build_max_heap(Jugador jugadores[], int tam){
    for (int i = tam / 2 - 1; i >= 0; i--) 
        heapify_max(jugadores, tam, i); 
}

void build_min_heap(Jugador jugadores[], int tam){
    for (int i = tam / 2 - 1; i >= 0; i--) 
        heapify_min(jugadores, tam, i); 
}

void Heap_Sort(Jugador jugadores[], int tam, int direction){

    enum{ASCENDENTE=0, DESCENDENTE};

    if(direction == ASCENDENTE){
        build_max_heap(jugadores, tam);
        for (int i=tam-1; i>=0; i--) 
        { 
            // Move current root to end 
            swap(&jugadores[0], &jugadores[i]); 
            // call max heapify on the reduced heap 
            heapify_max(jugadores, i, 0); 
        }
    }
    else{
        build_min_heap(jugadores, tam);
        for (int i=tam-1; i>=0; i--) 
        { 
            // Move current root to end 
            swap(&jugadores[0], &jugadores[i]); 
            // call max heapify on the reduced heap 
            heapify_min(jugadores, i, 0); 
        }
    }
}