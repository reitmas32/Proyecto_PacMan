#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP
#include <algoritmos/Jugadores.hpp>
#include <objetos/Tablero.hpp>

enum{ASCENDENTE=0, DESCENDENTE};

/**
 *@brief Función que imprime lso datos de los jugadores
 *
 *@param jugadores[] Lista de jugadores
 *
 *@param tam Tamñao de la lista de jugadores
 */
void print(Jugador jugadores[], int tam);

/**
 *@brief Función que imprime los datos de los jugadores en el Display
 *
 *@param jugadores[] Lista de jugadores
 *
 *@param tam Tamñao de la lista de jugadores
 */
void printWindow( std::vector<Jugador> jugadores, int tam);

/**
 *@brief Función que intercambia a jugadores de lugar
 *
 *@param num1 Primer jugador a intercambiar
 *
 *@param num2 Segundo jugador a intercambiar
 */
void swap(Jugador* num1, Jugador* num2);

/**
 *@brief Función que ordena al arreglo de forma ascendente
 *
 *@param jugadores[] Lista de jugadores a ordenar
 *
 *@param tam Tamaño del arreglo de jugaores
 *
 *@param k Pivote para ordenar la lista
 */
void heapify_max(Jugador jugadores[], int tam, int k);

/**
 *@brief Función que ordena al arreglo de forma descendente
 *
 *@param jugadores[] Lista de jugadores a ordenar
 *
 *@param tam Tamaño del arreglo de jugaores
 *
 *@param k Pivote para ordenar la lista
 */

void heapify_min(Jugador jugadores[], int tam, int k);

/**
 *@brief Función que crea un monticulo cuya raiz sea el mayor de los valores del arreglo
 *
 *@param jugadores[] Lista de jugadores a ordenar
 *
 *@param tam Tamaño del arreglo
 */
void build_max_heap(Jugador jugadores[], int tam);

 /**
 *@brief Función que crea un monticulo cuya raiz sea el menor de los valores del arreglo
 *
 *@param jugadores[] Lista de jugadores a ordenar
 *
 *@param tam Tamaño del arreglo
 */
void build_min_heap(Jugador jugadores[], int tam);

/**
 *@brief Función activadora del algoritmo
 *
 *@param jugadores[] Lista de jugadores a ordenar
 *
 *@param tam Tamaño del arreglo de jugadores
 *
 *@param direction Dirección de ordenamiento del arreglo
 */
void Heap_Sort(Jugador jugadores[], int tam, int direction);

#endif  //HEAPSORT_HPP