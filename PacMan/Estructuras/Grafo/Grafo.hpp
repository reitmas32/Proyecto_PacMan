/**!<Guardas de inclusión*/
#ifndef GRAFO_HPP
#define GRAFO_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include <string>
#include <cstring>
#include "Recursos/Map.hpp"
#include "Recursos/Vertex.hpp"
#include "Recursos/Couple.hpp"
#include "Recursos/DLL.hpp"
#include "Recursos/Stack.hpp"

/**
 *@class Graph
 *@brief Representa un grafo
 */
class Graph
{
private:

	/**!<Lista de vertex en el grafo*/
	Map<std::string,Vertex*> *vertices;

	/**
	 *@brief Método que imprime el value de una couple
	 *
	 *@param tmp Couple que se imprimira
	 */
	static void printCouple(Couple<std::string,Vertex*> *tmp);

	/**
	 *@brief Método que imprime el value de una couple y sus vecinos
	 *
	 *@param tmp Couple que se imprimira
	 */
	static void printCoupleN(Couple<std::string,Vertex*> *tmp);

	/**
	 *@brief Método que resetea los valores de un grafo
	 *
	 *@param tmp Couple que se editara su vertex
	 */
	static void setDefault(Couple<std::string,Vertex*>*tmp);


public:
	/**
	 *@brief Método constructor del grafo
	 */
	Graph();

	/**
	 *@brief Método destructor del grafo
	 */
	~Graph();

	/**
	 *@brief Método que agrega un vertex al grafo
	 *
	 *@param v Vertex que se agregara al grafo
	 *
	 *@return true si se logro agregar el vertex al grafo, en caso contrario retorna false
	 */
	bool add_vertex( Vertex *v );

	/**
	 *@brief Método que conecta dos vertex dentro del grafo
	 *
	 *@param edge1 Nombre del primer vertex a conectar
	 *
	 *@param edge2 Nombre del segundo vertex a conectar
	 *
	 *@return true si se lograron conectar los vertex, en caso contrario retorna false
	 */
	bool add_edge( std::string edge1, std::string edge2 );

	/**
	 *@brief Método que conecta dos vertex de forma dirigida dentro del grafo
	 *
	 *@param dge1 Nombre del primer vertex a conectar
	 *
	 *@param edge2 Nombre del segundo vertex a conectar
	 *
	 *@return true si se lograron conectar los vertex, en caso contrario retorna false
	 */
	bool add_edge_directed( std::string edge1, std::string edge2 );

	/**
	 *@brief Método que imprime los datos de los vertex en el grafo
	 */
	void print();

	/**
	 *@brief Método que imprime los vecinos de los vertex en el grafo
	 */
	void printNeighbor();

	/**
	 *@brief Método que nos regresa un vertex del grafo
	 *
	 *@param Vname Nombre del vertex a buscar
	 *
	 *@return Regresa un vertex
	 */
	Vertex *get_Vertex(std::string Vname);

	/**
	 *@brief Método que busca por anchura Breadth First Search
	 *
	 *@param nameStart Nombre del vertex donde iniciara la busqueda
	 */
	void BFS(std::string nameStart);

	int BFS_to(std::string nameStart, std::string nameEnd);

	/**
	 *@brief Método que regresa el map del grafo
	 *
	 *@return Map del grafo
	 */
	Map<std::string,Vertex*> *get_map();

	/**
	 *@brief Método que conecta dos vertex con peso
	 *
	 *@param edge1 Nombre del primer vertex a conectar
	 *
	 *@param edge2 Nombre del segundo vertex a conectar
	 *
	 *@param weigth Peso de la conexión entre los vertex
	 *
	 *@return true si se conectaron los vertex, en caso contrario retorna false
	 */
	bool add_edge_weighted( std::string edge1, std::string edge2, int weigth);

	/**
	 *@brief Método que indica el camino a seguir de un vertex a otro
	 *
	 *@param start Vertex de inicio
	 *
	 *@param end Vertex de final
	 *
	 *@return Stack con el camino a seguir
	 */
	Stack<std::string> *goTo(std::string start, std::string end);

};


#endif
