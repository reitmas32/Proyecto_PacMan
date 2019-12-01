#include "Jugadores.hpp"

bool Jugadores::obtenerJugadores() {
	/*Se abre el fichero que guarda a los jugadores*/
	FILE* file_in = fopen("HighScores.bin","rb");

	/*Si no existe se crea uno y se indica que esta vacio al 
	retornar false*/
	if(file_in == NULL){
		FILE* file_out = fopen("HighScores.bin","wb");
		fclose(file_out);
		return false;
	}
	
	/*En caso de que ya exista se lee y se guardan los 
	jugadores registrados en la lista de jugadores*/
	while(!feof(file_in)){
		Jugador jugador;
		fread(&jugador,sizeof(Jugador),1,file_in);
		this->jugadores.push_back(jugador);
	}
	
	printf("\n");
	
	/*Se cierra el fichero*/
	fclose(file_in);

	return true;

}

void Jugadores::escribirJugadores(){
	
	/*Se escribe el fichero con los datos de los juagadores*/
	FILE* file_out = fopen("HighScores.bin","wb");
	for(int i = 0; i<5; i++){
		/*Se escriben los datos*/
		fwrite(&jugadores[i], sizeof(Jugador), 1, file_out);
	}

	/*Se cierra el fichero*/
	fclose(file_out);
	
}

std::vector<Jugador> Jugadores::getJugadores(){
	
	/*Si existe el fichero con los jugadores los retorna*/
	if(this->obtenerJugadores()){
		return this->jugadores;
	}else{
		/*Sino existe retorna una lista vacía*/
		std::vector<Jugador> tmp;
		return tmp;
	}

	
}

void Jugadores::setJugadores(std::vector<Jugador> jugadores){
	this->jugadores = jugadores;
}