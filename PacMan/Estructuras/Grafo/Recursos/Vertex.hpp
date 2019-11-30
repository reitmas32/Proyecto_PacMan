/**!<Guardas de inclusión*/
#ifndef VERTEX_HPP
#define VERTEX_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <string>
#include "DLL.hpp"

/**
 *@class Vertex
 *@brief Representa un vertices en un grafo
 */
class Vertex
{
public:
	/**!<Enumeración de los colores de un Vertex*/
	enum class Colors { BLACK, GRAY, WHITE };

private:
	/**!<Campo de texto. Se utilizará como key*/
	std::string name;

	/**!<Lista de vértices adyecentes*/
	DLL<Vertex*> *neighbors; 

	/**!<Distancia entre los nodos*/
	int distance{ 0 };

	/**!<Color del vertex*/
	Colors color{ Colors::BLACK };

	/**!<Predecesor del vertex*/
	std::string predecesor = "";

	/**!<Peso del vertex*/
	int weigth{ 0 };

	/**!<Tiempo en el que fue descubierto el vertex*/
	size_t discovery_time{ 0 };

	/**!<*/
	size_t finish_time{ 0 };

	/**!<*/
	int x { 0 };

	/**!<*/
	int y { 0 };

	/**
	 *@brief Método que se inyecta a la lista para imprimir los vecinos del vertex
	 *
	 *@param _v Vertice que se imprimira su nombre
	 */
	static void printN(Vertex* _v);
public:
	/**
	 *@brief Método constructor del Vertex
	 */
	Vertex();
	/**
	 *@brief Método constructor del Vertex
	 *
	 *@param name Nombre del vertex
	 */
	Vertex( std::string name );
	
	/**
	 *@brief Método constructor del Vertex
	 *
	 *@param name Nombre del vertex
	 *
	 *@param x
	 *
	 *@param y
	 */
	Vertex( std::string name, std::string x, std::string y );

	/**
	 *@brief Método destructor del vertex
	 */
	~Vertex();
	/**
	 *@brief Método que regresa el nomrbe del Vertex
	 *
	 *@return Nombre del Vertex
	 */
	std::string get_name() const;

	/**
	 *@brief Método que agrega un vecino al vertex
	 *
	 *@param v Vertex vecino
	 */
	void add_neighbor( Vertex *v );

	/**
	 *@brief Método que imprime los vecinos del vertex
	 */
	void print_neighbors();

	/**
	 *@brief Método que imprime los datos del vertex
	 */
	void print();

	/**
	 *@brief Método que define la distancia del vertex
	 *
	 *@param d Distancia
	 */
	void set_distance( int d );

	/**
	 *@brief Método que retorna la distancia del vertex
	 *
	 *@param Retorna la distancia del vertex
	 */
	int get_distance();

	/**
	 *@brief Método que define el color del vertex
	 *
	 *@param c Color del vertex
	 */
	void set_color( Colors c );

	/**
	 *@brief Método que retorna el color del vertex
	 *
	 *@return Color del vertex
	 */
	Vertex::Colors get_color();

	/**
	 *@brief Método que define el predecesor del vertex
	 *
	 *@param p Nombre del predecesor del vertex
	 */
	void set_predecesor( std::string p );

	/**
	 *@brief Método que retorna el predecesor del vertex
	 *
	 *@return Nombre del vertex predecesor
	 */
	std::string get_predecesor();

	/**
	 *@brief Método que retorna los vecinos del vertex
	 *
	 *@return Lista de vecinos del vertex
	 */
	DLL<Vertex*>* get_neighbors();

	/**
	 *@brief Método que retorna el peso del Nodo
	 *
	 *@return Peso del vertex
	 */
	int get_weigth();

	/**
	 *@brief Método que define el peso del nodo
	 *
	 *@param w Peso del nodo
	 */
	void set_weigth( int w);

	/**
	 *@brief Método que retorna el tiempo final del vertex
	 *
	 *@return Tiempo final del vertex
	 */
	int get_finish_time();

	/**
	 *@brief Método que define el tiempo final del vertex
	 *
	 *@param ft Tiempo final del vertex
	 */
	void set_finish_time(size_t ft);

	/**
	 *@brief Método que retorna el tiempo de descubrimiento del vertex
	 *
	 *@param Tiempo de descubirmiento del vertex
	 */
	int get_discovery_time();

	/**
	 *@brief Método que define el tiempo de descubirmiento del vertex
	 *
	 *@param ft Tiempo en el que se descubrio el vertex
	 */
	void set_discovery_time(size_t ft);

};
#endif