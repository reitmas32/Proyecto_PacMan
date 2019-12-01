#include "Jugadores.hpp"

void Jugadores::obtenerJugadores() {
	FILE* file_in = fopen("HighScores.bin","rb");
	
	while(!feof(file_in)){
		Jugador jugador;
		fread(&jugador,sizeof(Jugador),1,file_in);
		this->jugadores.push_back(jugador);
	}
	
	printf("\n");
	
	fclose(file_in);

}

void Jugadores::escribirJugadores(){
	
	FILE* file_out = fopen("HighScores.bin","wb");
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