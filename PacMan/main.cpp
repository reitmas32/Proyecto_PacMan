#include "../Estructuras/Grafo/Grafo.hpp"

int main()
{	
#if 1
	Graph *g = new Graph();

	g -> add_vertex(new Vertex("A"));
	g -> add_vertex(new Vertex("B"));
	g -> add_vertex(new Vertex("C"));
	g -> add_vertex(new Vertex("D"));
	g -> add_vertex(new Vertex("E"));
	g -> add_vertex(new Vertex("F"));
	g -> add_vertex(new Vertex("G"));
	g -> add_vertex(new Vertex("H"));
	g -> add_vertex(new Vertex("I"));
	g -> add_vertex(new Vertex("J"));
	g -> add_vertex(new Vertex("K"));

	g -> add_edge("E","A");
	g -> add_edge("A","B");
	g -> add_edge("B","C");
	g -> add_edge("F","B");
	g -> add_edge("E","I");
	g -> add_edge("I","F");
	g -> add_edge("F","G");
	g -> add_edge("G","J");
	g -> add_edge("K","G");
	g -> add_edge("H","D");
	g -> add_edge("K","H");

	/*Grafo antes de goTo*/
	g -> print();
	std::cout << "=========================" << std::endl;

	/*Ejemplo de uso de goTo*/

	/*La usamos*/
	Stack<std::string> *pila = g ->goTo("A","C");

	/*Grafo despues de goTo*/
	g -> print();

	/*Utilizamos la pila*/

	while(!pila ->IsEmpty()){
		std::cout << "Pila: " << pila ->Pop() << std::endl;
	}

	/*Liberamos memoria*/
	delete pila;
	delete g;
#endif
}