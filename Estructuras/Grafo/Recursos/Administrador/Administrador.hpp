/**!<Guardas de inclusión*/
#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

/**!<Bibliotecas necesarias*/
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <cstring>

class Administrador{

private:
	/**!<*/
	std::string RUTA_DATOS = "./datos/";

	/**!<*/
	std::string NOMBRE_ARCHIVO_NODOS = "Nodos.txt";

	/**!<*/
	std::string NOMBRE_ARCHIVO_EDGES = "Edges.txt";

public:
	/**
	 *@brief Método constructor del Administrador
	 */
	Administrador();

	/**
	 *@brief
	 */
	std::list< std::string > getNodos();

	/**
	 *@brief
	 */
	std::list< std::string > getEdges();

};
#endif