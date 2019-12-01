#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include "Jugadores.hpp"

void print( Jugador jugadores[], int tam);

void swap(Jugador* num1, Jugador* num2);

void heapify_max(Jugador jugadores[], int tam, int k);

void heapify_min(Jugador jugadores[], int tam, int k);
void build_max_heap(Jugador jugadores[], int tam);

void build_min_heap(Jugador jugadores[], int tam);

void Heap_Sort(Jugador jugadores[], int tam, int direction);

#endif  //HEAPSORT_HPP