#include "Vertex.hpp"

Vertex::Vertex()
{
	this->neighbors = new DLL<Vertex*>();
}

Vertex::Vertex( std::string _name )
{
	name = _name;
	this->neighbors = new DLL<Vertex*>();
}

Vertex::Vertex( std::string _name, std::string _x, std::string _y )
{
	this->name = _name;
	this->x = std::stoi(_x);
	this->y = std::stoi(_y);
	this->neighbors = new DLL<Vertex*>();
} 

Vertex::~Vertex(){
	delete neighbors;
}

void Vertex::add_neighbor( Vertex *v )
{
	this ->neighbors ->InsertBack(v);
}


std::string Vertex::get_name() const
{
	return this->name;
}

void Vertex::printN(Vertex *_v){
	std::cout << _v -> get_name() << "-> ";
		
}

void Vertex::print_neighbors()
{
	std::cout<< name << ": ";
	this -> neighbors ->Traverse(printN);
	std::cout << "Nil\n";
}

void Vertex::print(){
	std::string color;
	switch(this->color){
		case Vertex::Colors::BLACK: color = "BLACK"; break;
		case Vertex::Colors::GRAY: color = "GRAY"; break;
		case Vertex::Colors::WHITE: color = "WHITE"; break;
	}
	//std::cout << this->name << " " << this->distance <<" "<< color<<" "<<this->predecesor<<" "<<this->weigth<<" "<<this->discovery_time <<"/"<< this->finish_time;
	std::cout << this->name <<", x: "<< this->x <<", y: "<< this->y << ", d: "<< this->distance;
	std::cout << "\n";
}

void Vertex::set_distance( int d){
	this->distance = d;
}

int Vertex::get_distance(){
	return this->distance;
}

void Vertex::set_color( Vertex::Colors c ){
	this->color = c;
}

Vertex::Colors Vertex::get_color(){
	return this->color;
}

void Vertex::set_predecesor( std::string p){
	this->predecesor = p;
}

std::string Vertex::get_predecesor(){
	return this->predecesor;
}

DLL<Vertex*>* Vertex::get_neighbors(){
	return this->neighbors;
}

int Vertex::get_weigth(){
	return this->weigth;
}
	
void Vertex::set_weigth( int w){
	this->weigth = w;
}

int Vertex::get_finish_time(){
	return this->finish_time;
}

void Vertex::set_finish_time(size_t ft){
	this->finish_time = ft;
}

int Vertex::get_discovery_time(){
	return this->discovery_time;
}

void Vertex::set_discovery_time(size_t ft){
	this->discovery_time = ft;
}

void Vertex::set_X( int _x ){
	this->x = _x;
}
	
void Vertex::set_Y( int _y ){
	this->y = _y;
}

int Vertex::get_X(){
	return this->x;
}

int Vertex::get_Y(){
	return this->y;
}
