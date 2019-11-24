#include "Grafo.hpp"

int main()
{	

	Graph *g = new Graph();

	bool a= g ->add_vertex(new Vertex("A"));
	bool b = g ->add_vertex(new Vertex("B"));
	g -> add_vertex(new Vertex("C"));

	g->print();
	std::cout << "Estado de insercion de A: " << a << std::endl;
	std::cout << "Estado de insercion de B: " << b << std::endl;

	bool edge = g -> add_edge_directed("A","B");
	g -> add_edge_weighted("A","C",1);

	std::cout << "Estado de edge de A y B: " << edge << std::endl;

	Vertex *vertex = g -> get_Vertex("A");

	
	vertex -> add_neighbor(new Vertex("prueba"));

	vertex -> print();

	g->printNeighbor();

	Map<std::string, Vertex*>* map = g ->get_map();

	map -> insert("vacio",new Vertex("vacio"));

	g -> print();


	delete g;

}