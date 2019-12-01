/**!<Guardas de inclusión*/
#ifndef JUGADORES_HPP
#define JUGADORES_HPP

/**!<Bibliotecas necesarias*/
#include <stdio.h>
#include <iostream>
#include <vector>

/**
 *@struct Jugador
 *@brief Representa al usuario que esta jugando
 */
typedef struct Jugador{
	
	/**!<Es el nombre del jugador*/
	char name[32];

	/**!<Es el puntaje obtenido por el usuario*/
	int value;

	/**!<Sobrecarga de operadores >*/
	bool operator>( Jugador& rhs ) { return this->value > rhs.value; }

	/**!<Sobrecarga de operadores <*/
	bool operator<( Jugador& rhs ) { return this->value < rhs.value; }
	
}Jugador;

/**
 *@struct Jugadores
 *@brief Representa un administrador que gestiona los datos de los usuarios
 */
struct Jugadores{
	/**!<Es el conjunto de usuarios con los que se va trabajar*/
	std::vector<Jugador> jugadores;

	/**
	 *@brief Función que lee, de un archivo, los datos de los jugadores.
	 *
	 *@return True si logro obtener los datos, en caso contrario  retorna false
	 */
	bool obtenerJugadores();

	/**
	 *@brief Función que guarda, en un archivo, los datos de los jugadores 
	 */
	void escribirJugadores();

	/**
	 *@brief Función que obtiene la lista de jugadores
	 *
	 *@return Lista de jugadores
	 */
	std::vector<Jugador> getJugadores();

	/**
	 *@brief Función que establece la lista de jugadores
	 */
	void setJugadores(std::vector<Jugador> jugadores);
};

#endif	//JUGADORES_HPP