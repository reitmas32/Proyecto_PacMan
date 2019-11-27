#include <iostream>
#include "Map.hpp"
#include "Recursos/DLL.hpp"
#include "Recursos/Couple.hpp"

void print(Couple<char,int>* item){
	std::cout << "Key: " << item->getKey() << " Value: " << item ->getValue() << std::endl;
}


int main(){
	Map<char,int> *map = new Map<char,int>();

	map ->insert('a',100);
	map ->insert('b',200);

	DLL<Couple<char,int>*> *list2 = map->getMap();

	std::cout << std::endl;

	list2 ->Traverse(print);

	std::cout << std::endl;

	/*Buscamos a A*/

	map ->search('a');

	Couple<char,int>* a = map ->getCursor();

	a ->setValue(9999);

	DLL<Couple<char,int>*> *list = map->getMap();

	Couple<char,int>* acopia;

	list ->Peek(&acopia);

	acopia ->setValue(1);

	list ->Traverse(print);

	std::cout <<"Antes de vacias el map" << std::endl;

	map ->MakeEmpty();

	list ->Traverse(print);

	std::cout <<"Despues de vaciar el map" << std::endl;











	delete map;
}