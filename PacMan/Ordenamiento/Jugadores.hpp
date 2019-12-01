#ifndef JUGADORES_HPP
#define JUGADORES_HPP

#include <stdio.h>
#include <iostream>
#include <vector>

typedef struct Jugador{
	
	char name[32];
	int value;
	bool operator>( Jugador& rhs ) { return this->value > rhs.value; }
	bool operator<( Jugador& rhs ) { return this->value < rhs.value; }
	
}Jugador;

struct Jugadores{
	std::vector<Jugador> jugadores;
	void obtenerJugadores();
	void escribirJugadores();
	std::vector<Jugador> getJugadores();
	void setJugadores(std::vector<Jugador> jugadores);
};

#endif	//JUGADORES_HPP