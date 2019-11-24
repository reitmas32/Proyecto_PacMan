#include "Grafo.hpp"

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

#if 0
void Graph::BSF(std::string nameStart){

	for(auto &v: this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor("Nil");
	}
	
	auto &start = this->vertices.find(nameStart)->second;
	start.set_color(Vertex::Colors::GRAY);
	
	#if 1

	std::list<Vertex> q;
	q.push_front(start);

	while(!q.empty()){

		Vertex v = q.front();
		q.pop_front();
		
		for(auto &w: this->vertices.find(v.get_name())->second.get_neighbors()){

			if(this->vertices.find(w.get_name())->second.get_color() == Vertex::Colors::BLACK){
				this->vertices.find(w.get_name())->second.set_color(Vertex::Colors::GRAY);
				
				int dist = this->vertices.find(v.get_name())->second.get_distance();
				this->vertices.find(w.get_name())->second.set_distance(dist+1);
				this->vertices.find(w.get_name())->second.set_predecesor(v.get_name());
				q.push_back(w);
			}
		}
		this->vertices.find(v.get_name())->second.set_color(Vertex::Colors::WHITE);
	}

	#endif
}

void Graph::dfs_traverse(std::string nameV, size_t* time){
	
	++*time;

	this->vertices.find(nameV)->second.set_discovery_time(*time);
	this->vertices.find(nameV)->second.set_color(Vertex::Colors::GRAY);

	for( auto &u: this->vertices.find(nameV)->second.get_neighbors()){
		if(this->vertices.find(u.get_name())->second.get_color() == Vertex::Colors::BLACK){
			this->vertices.find(u.get_name())->second.set_predecesor(nameV);
			dfs_traverse(u.get_name(), time);
		}
	}

	this->vertices.find(nameV)->second.set_color(Vertex::Colors::WHITE);

	++*time;

	this->vertices.find(nameV)->second.set_finish_time(*time);
}

void Graph::DFS(std::string nameStart){

	size_t time = 0;

	for(auto &v: this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor("Nil");
		v.second.set_discovery_time(0);
		v.second.set_finish_time(0);
	}

	dfs_traverse(nameStart, &time);
	
}

void Graph::dfs_traverse_to(std::string nameV, int* time, std::vector<Vertex>* lista){

	++*time;
	
	this->vertices.find(nameV)->second.set_discovery_time(*time);
	this->vertices.find(nameV)->second.set_color(Vertex::Colors::GRAY);

	for( auto &u: this->vertices.find(nameV)->second.get_neighbors()){
		if(this->vertices.find(u.get_name())->second.get_color() == Vertex::Colors::BLACK){
			this->vertices.find(u.get_name())->second.set_predecesor(nameV);
			dfs_traverse_to(u.get_name(), time, lista);
		}
	}

	this->vertices.find(nameV)->second.set_color(Vertex::Colors::WHITE);

	++*time;

	this->vertices.find(nameV)->second.set_finish_time(*time);

	lista->push_back(this->vertices.find(nameV)->second);
}


std::vector<Vertex> Graph::dfs_to(std::string nameStart){
	static int time = 0;

	for(auto &v: this->vertices){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_predecesor("Nil");
		v.second.set_discovery_time(0);
		v.second.set_finish_time(0);
	}	

	std::vector<Vertex> lista;

	dfs_traverse_to(nameStart, &time, &lista);

	std::sort (lista.begin(), lista.end(),
		[](Vertex& lhs, Vertex& rhs)->bool{
			return lhs.get_finish_time() > rhs.get_finish_time();
		} );

	return lista;

}

void Graph::create_Graph(){
	//
}


void Graph::cargar_Plano(){
	
	std::vector< std::string > datos;

	for( auto s : this->admon.getNodos() ){
		char *cstr = new char [s.size()+1];
		std::strcpy( cstr, s.c_str() );
		char *token = strtok( cstr, ":" );
		//while( token != NULL ){
		for( int i = 0; i < 3; ++i ){
			datos.push_back( token );
			token = strtok( NULL, ":" );
		}
		this->add_vertex( Vertex( datos[0], datos[1], datos[2] ) );
		datos.clear();
		delete[] cstr;
	}

	datos.clear();

	for( auto s : this->admon.getEdges() ){
		char *cstr = new char [ s.size() ];
		std::strcpy( cstr, s.c_str() );
		char *token = strtok( cstr, ":" );
		//while( token != NULL ){
		for( int i = 0; i < 2; ++i ){
			datos.push_back( token );
			token = strtok( NULL, ":" );
		}
		this->add_edge( datos[0], datos[1] );
		datos.clear();
		delete[] cstr;
	}
}
#endif

