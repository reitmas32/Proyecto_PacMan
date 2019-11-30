/**!<Bibliotecas necesarias*/
#include <stdio.h>
#include <iostream>
#include <vector>

/**
 *@struct Jugador
 *@brief Representa al usuario que esta jugando.
 */
typedef struct Jugador{
	/**!<Es el nombre del usuario*/
	char name[32];

	/**!<Es el puntaje obtenido por el usuario*/
	int value;

	/**!<Sobrecarga de operadores >, <*/
	bool operator>( Jugador& rhs ) { return this->value > rhs.value; }
	bool operator<( Jugador& rhs ) { return this->value < rhs.value; }
	
}Jugador;

/**
* @struct Jugadores
* @brief Representa un administrador que gestiona los datos de los usuarios.
*/
struct Jugadores{
	/**!<Es el conjunto de usuarios con el que se va a trabajar*/
	std::vector<Jugador> jugadores;

	/*
	 *@brief Función que lee, de un archivo, los datos de los jugadores.
	 */
	void obtenerJugadores();

	/**
	* @brief Función que guarda, en un archivo, los datos de los jugadores.
	*/
	void escribirJugadores();

	/**
	* @brief Función que obtiene la lista de jugadores.
	*
	* @return Vector de jugadores.
	*/
	std::vector<Jugador> getJugadores();

	/**
	* @brief Función que establece la lista de jugadores.
	*
	* @param Vector de jugadores. 
	*/
	void setJugadores(std::vector<Jugador> jugadores);
};

void Jugadores::obtenerJugadores() {
	/**!<Se abre el archivo de trabajo*/
	FILE* file_in = fopen("HighScores.bin","rb");

	/**!<Se cargan los datos del archivo*/	
	while(!feof(file_in)){
		Jugador jugador;
		fread(&jugador,sizeof(Jugador),1,file_in);
		this->jugadores.push_back(jugador);
	}
	
	printf("\n");
	
	fclose(file_in);

}

void Jugadores::escribirJugadores(){
	/**!<Se abre el archivo de trabajo*/
	FILE* file_out = fopen("HighScores.bin","wb");

	/**!<Se guardan los datos en el archivo*/	
	for(int i = 0; i<5; i++){
		fwrite(&jugadores[i], sizeof(Jugador), 1, file_out);
	}
	fclose(file_out);
	
}

std::vector<Jugador> Jugadores::getJugadores(){
	this->obtenerJugadores();
	return this->jugadores;
}

void Jugadores::setJugadores(std::vector<Jugador> jugadores){
	this->jugadores = jugadores;
}