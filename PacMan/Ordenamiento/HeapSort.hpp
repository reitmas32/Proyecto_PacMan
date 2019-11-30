/**!<Guardas de inclusión*/
#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

/**!<Bibliotecas necesarias*/
#include <stdio.h>
#include <stdbool.h>
#include "Jugadores.hpp"

/**
 * @brief Función que imprime los datos del jugador.
 *
 * @param jugadores Arreglo de tipo Jugador.
 *
 * @param tam Número de elementos en el arreglo.
 */
void print( Jugador jugadores[], int tam);

/**
 * @brief Función que invierte la posición de dos jugadores.
 *
 * @param num1 Primer Jugador
 *
 * @param num2 Segundo Jugador 	
 */
void swap(Jugador* num1, Jugador* num2);

/**
 * @brief Función que crea y ordena el arreglo en forma ascendente.
 *
 * @param jugadores Arreglo de tipo Jugador.
 *
 * @param tam Número de elementos en el arreglo.
 *
 * @param k Pivote para ordenar el arreglo.
 */
void heapify_max(Jugador jugadores[], int tam, int k);

/**
 * @brief Función que crea y ordena el arreglo en forma descendente.
 *
 * @param jugadores Arreglo de tipo Jugador.
 *
 * @param tam Número de elementos en el arreglo.
 *
 * @param k Pivote para ordenar el arreglo.
 */
void heapify_min(Jugador jugadores[], int tam, int k);

/**
 * @brief Función que construye un montículo cuya raíz sea el mayor de los valores del arreglo.
 *
 * @param jugadores Arreglo de tipo Jugador.
 *
 * @param tam Número de elementos en el arreglo.
 */
void build_max_heap(Jugador jugadores[], int tam);

/**
 * @brief Función que construye un montículo cuya raíz sea el menor de los valores del arreglo.
 *
 * @param jugadores Arreglo de tipo Jugador.
 *
 * @param tam Número de elementos en el arreglo.
 */
void build_min_heap(Jugador jugadores[], int tam);

/**
 * @brief Función activadora del algortimo.
 *
 * @param jugadores Arreglo de tipo Jugador.
 *
 * @param tam Número de elementos en el arreglo.
 *
 * @param direction Dirección de ordenamiento del arreglo.
 */
void Heap_Sort(Jugador jugadores[], int tam, int direction);

#endif