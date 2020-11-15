#include <estructuras/Grafo.hpp>

//==============Métodos privados==================
void Graph::printCouple(Couple<std::string,Vertex*> *tmp){
	Vertex *v = tmp -> getValue();

	std::cout << std::endl;
	v ->print();
}

void Graph::printCoupleN(Couple<std::string,Vertex*> *tmp){
	Vertex *v = tmp -> getValue();

	std::cout << std::endl;
	v ->print_neighbors();
}

void Graph::setDefault(Couple<std::string,Vertex*>*tmp){
	Vertex *v = tmp -> getValue();

	v -> set_color(Vertex::Colors::BLACK);
	v -> set_distance(0);
	v -> set_predecesor("Nil");

}
//================================================
Graph::Graph()
{
	/**!<Crea la lista de vertices*/
	vertices = new Map<std::string,Vertex*>();
}

Graph::~Graph()
{
	/*Elimina la lista de vertices*/
	delete vertices;
}

bool Graph::add_vertex( Vertex *v )
{
	return vertices -> insert(v -> get_name(), v);
}

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	/**!<Uno o ambos nodos no existen*/
	bool res = false;

	/*Verifica que esten los nodos en el grafo*/
	if(vertices -> find(edge1) && vertices -> find(edge2)){

		/*Buscamos el vertex en el map*/
		vertices ->search(edge1);

		/*Obtenemos la pareja de datos*/
		Couple<std::string,Vertex*> *v1 = vertices ->getCursor();

		/*Buscamos el vertex en el map*/
		vertices ->search(edge2);

		/*Obtenemos la pareja de datos*/
		Couple<std::string,Vertex*> *v2 = vertices ->getCursor();

		/*Obtenemos el vertex de la pareja*/
		Vertex *vertex1 = v1 ->getValue();
		Vertex *vertex2 = v2 ->getValue();

		/*Los enlazamos*/
		vertex1 -> add_neighbor(vertex2);
		vertex2 -> add_neighbor(vertex1);
		res = true;
	}

	return res;
}

bool Graph::add_edge_directed( std::string edge1, std::string edge2 ){
	/**!<Uno o ambos nodos no existen*/
	bool res = false;

	/*Verifica que esten los nodos en el grafo*/
	if(vertices -> find(edge1) && vertices -> find(edge2)){

		/*Buscamos el vertex en el map*/
		vertices ->search(edge1);

		/*Obtenemos la pareja de datos*/
		Couple<std::string,Vertex*> *v1 = vertices ->getCursor();

		/*Buscamos el vertex en el map*/
		vertices ->search(edge2);

		/*Obtenemos la pareja de datos*/
		Couple<std::string,Vertex*> *v2 = vertices ->getCursor();

		/*Obtenemos el vertex de la pareja*/
		Vertex *vertex1 = v1 ->getValue();
		Vertex *vertex2 = v2 ->getValue();

		/*Los enlazamos*/
		vertex1 -> add_neighbor(vertex2);
		res = true;
	}

	return res;
}

bool Graph::add_edge_weighted( std::string edge1, std::string edge2, int weigth = 1){
	
	bool res = false;

	/*Conecta los vertex*/
	if( add_edge_directed(edge1, edge2)){

		/*Buscamos el vertex en el map*/
		vertices ->search(edge1);

		/*Obetenmos la pareja de datos*/
		Couple<std::string,Vertex*> *v1 = vertices ->getCursor();
		
		/*Obtenemos el vertex de la pareja*/
		Vertex *vertex1 = v1 ->getValue();

		/*Define el peso*/
		vertex1-> set_weigth(weigth);

		res = true;
	}

	return res;
}


Vertex *Graph::get_Vertex(std::string Vname){
	
	/*Buscamos el vertex en el map*/
	vertices ->search(Vname);

	/*Obetenmos la pareja de datos*/
	Couple<std::string,Vertex*> *v = vertices ->getCursor();
		
	/*Obtenemos el vertex de la pareja*/
	return v ->getValue();
}

Map<std::string,Vertex*> *Graph::get_map(){
	return this->vertices;
}

void Graph::print()
{
	DLL<Couple<std::string,Vertex*>*> *list = vertices -> getMap();

	list ->Traverse(printCouple);
}

void Graph::printNeighbor(){
	DLL<Couple<std::string,Vertex*>*> *list = vertices -> getMap();

	list ->Traverse(printCoupleN);	

}

#if 0
void print_list(std::list<Vertex> list){
	for(auto v: list){ std::cout<<v.get_name(); }
}
#endif

void Graph::BFS(std::string nameStart){
	/*Obtenemos el mapa*/
	Map<std::string, Vertex*>* map = this -> get_map();

	/*Obtenemos la DLL del map*/
	DLL<Couple<std::string,Vertex*>*> *list = map ->getMap();

	/*Reseteamos todos los atributos de un vertex*/
	list ->Traverse(setDefault);

	/*Buscamos al primer vertex en el grafo*/
	vertices -> search(nameStart);

	/*Obtenemos a la pareja que contiene al vertex*/
	Couple<std::string,Vertex*> *couple = vertices -> getCursor();

	/*Obtenemos al vertex*/
	Vertex *start = couple -> getValue();

	/*Creamo a la pila*/
	Stack<Vertex*> *q = new Stack<Vertex*>();

	/*Agregamos a start a la pila*/
	q -> Push(start);

	while(!q -> IsEmpty()){
		Vertex *v = q -> Pop();

		/*Obtenemos a los vecinos del vertex v*/
		DLL<Vertex*> *neighbors = v ->get_neighbors();

		/*Recorremos todos los vecinos de v*/
		for(Node<Vertex*> *it = neighbors -> getFirst(); it != NULL; it = it -> next){

			Vertex *w = it -> data;

			if(w -> get_color() == Vertex::Colors::BLACK){
				w -> set_color(Vertex::Colors::GRAY);

				int dist = v -> get_distance();
				w -> set_distance(dist +1);
				w -> set_predecesor(v -> get_name());
				q -> Push(w);
			}
		}
		v -> set_color(Vertex::Colors::WHITE);	
	}

	/*Eliminamos la pila*/
	delete q;
}

int Graph::BFS_to(std::string nameStart, std::string nameEnd){
	/*Obtenemos el mapa*/
	Map<std::string, Vertex*>* map = this -> get_map();

	/*Obtenemos la DLL del map*/
	DLL<Couple<std::string,Vertex*>*> *list = map ->getMap();

	/*Reseteamos todos los atributos de un vertex*/
	list ->Traverse(setDefault);

	/*Buscamos al primer vertex en el grafo*/
	vertices -> search(nameStart);

	/*Obtenemos a la pareja que contiene al vertex*/
	Couple<std::string,Vertex*> *couple = vertices -> getCursor();

	/*Obtenemos al vertex*/
	Vertex *start = couple -> getValue();

	/*Creamo a la pila*/
	Stack<Vertex*> *q = new Stack<Vertex*>();

	/*Agregamos a start a la pila*/
	q -> Push(start);

	while(!q -> IsEmpty()){
		Vertex *v = q -> Pop();

		/*Obtenemos a los vecinos del vertex v*/
		DLL<Vertex*> *neighbors = v ->get_neighbors();

		/*Recorremos todos los vecinos de v*/
		for(Node<Vertex*> *it = neighbors -> getFirst(); it != NULL; it = it -> next){

			Vertex *w = it -> data;

			if(w -> get_color() == Vertex::Colors::BLACK){
				w -> set_color(Vertex::Colors::GRAY);

				int dist = v -> get_distance();
				w -> set_distance(dist +1);
				w -> set_predecesor(v -> get_name());
				q -> Push(w);
				if(w->get_name() == nameEnd){
					/*Eliminamos la pila*/
					delete q;
					return 0;
				}
			}
		}
		v -> set_color(Vertex::Colors::WHITE);	
	}

	/*Eliminamos la pila*/
	delete q;
	return 0;
}

Stack<std::string> *Graph::goTo(std::string start, std::string end)
{
	this ->BFS_to(start,end);
	Stack<std::string> *pila = new Stack<std::string>();

	/*Buscamos a end en el map*/
	vertices ->search(end);

	/*Obtenemos a la couple que contiene a end*/
	Couple<std::string,Vertex*> *coupleV = vertices -> getCursor();

	/*Obtenemos a end*/
	Vertex *v = coupleV -> getValue();

	pila ->Push(v -> get_name());

	std::string s = v -> get_predecesor();

	while(s != start){
		pila ->Push(s);

		/*Buscamos a s en el map*/
		vertices -> search(s);

		/*Obtenemos a la couple que contiene a s*/
		Couple<std::string,Vertex*> *coupleW = vertices -> getCursor();

		/*Obtenemos a s*/
		Vertex *w = coupleW -> getValue();

		s = w -> get_predecesor();
	}
	pila ->Push(s);

	return pila;

}

