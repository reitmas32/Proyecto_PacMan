#include "Administrador.hpp"

Administrador::Administrador(){
  /*Constructor vacío*/
}

std::list<std::string> Administrador::getNodos(){
	
	std::list<std::string> nodos;
	
	FILE* file_nodos = fopen(
		(this->RUTA_DATOS + this->NOMBRE_ARCHIVO_NODOS).c_str()
		, "r" );

	if( file_nodos == NULL ){
    	std::cout << "\nEl archivo "<<
      this->NOMBRE_ARCHIVO_NODOS <<
      " no pudo ser abierto para lectura.\n";
    	exit( -1 );
   	}

   	char nodo_Info[81];

   	while( !feof( file_nodos ) ){
   		if( !feof( file_nodos ) ){
   			fgets( nodo_Info, 81, file_nodos );
   			nodos.push_back( nodo_Info );
   		}
   	}

   	fclose( file_nodos );

   	return nodos;
}

std::list<std::string> Administrador::getEdges(){
	std::list<std::string> edges;
	
	FILE* file_edges = fopen(
		(this->RUTA_DATOS + this->NOMBRE_ARCHIVO_EDGES).c_str(), "r" );

	if( file_edges == NULL ){
    	std::cout << "\nEl archivo "<<
    	this->NOMBRE_ARCHIVO_EDGES <<
    	" no pudo ser abierto para escritura.\n";
    	exit( -1 );
   	}

   	char edges_pair[10];

   	while( !feof( file_edges ) ){
   		if( !feof( file_edges ) ){
   			fgets( edges_pair, 10, file_edges );
   			char *token = strtok( edges_pair, "\n" );
   			edges.push_back( token );
   		}
   	}

   	fclose( file_edges );

   	return edges;
}