#include "Vertex.hpp"

void printN(Vertex *_v){
	std::cout << _v -> get_name() << "-> ";
	std::cout << "Nil\n";	
}

int main(){
	Vertex *v1 = new Vertex("prueba");
	Vertex *v2 = new Vertex("b");
	Vertex *v3 = new Vertex("c");

	DLL<Vertex*> *list = v1 -> get_neighbors();



	v1 ->add_neighbor(v2);
	v1 ->add_neighbor(v3);

	Vertex *tmp;
	list -> RemoveBack(&tmp);
	
	v1 -> print_neighbors();

	v1 ->print();



	list ->Traverse(printN);


	delete v1;
	delete v2;
	delete v3;
}