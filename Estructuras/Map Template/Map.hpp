/**!<Guardas de inclusión*/
#ifndef MAP_HPP
#define MAP_HPP

/**!<Bibliotecas necesarias*/
#include <iostream>
#include "Recursos/DLL.hpp"
#include "Recursos/Couple.hpp"

/**
 *@class Map
 *@brief Estructura que almacenara una lista de Couples
 */
template<typename Key, typename Value> 
class Map{
	private:
		/**!<Lista de Couples*/
		DLL<Couple<Key,Value>*> *map;

		/**
		 *@brief Método encargado de comparar dos couples
		 *
		 *@param key1 Clave del primer objeto a comparar
		 *
		 *@param key2 Clave del segundo objeto a comparar
		 *
		 *@return true si son iguales las keys en caso contrario false
		 */
		static bool compareCouple(Couple<Key,Value> *key1,Couple<Key,Value> *key2);
	public:
		/**
		 *@brief Método constructor de Map
		 */
		Map();

		/**
		 *@brief Método destructor de Map
		 */
		~Map();

		/**
		 *@biref Método encargado de insertar un elemento al map
		 *
		 *@param _key Clave de la couple a insertar
		 *
		 *@param _value Información de la couple a insertar
		 */
		void insert(Key _key,Value _value);

		/**
		 *@brief Método encargado de borrar uan couple del map
		 *
		 *@param _key Clave de la couple que se eliminara del map
		 *
		 *@param _data_back Información de la couple que se eliminara
		 *
		 *@return true si se logro eliminar la couple del map en caso contrario retorna false
		 */
		bool remove(Key _key, Value *_data_back);

		/**
		 *@brief Método que nos regresa la lista de couples
		 *
		 *@return Una DLL
		 */

		DLL<Couple<Key,Value>*> *getMap();

		/**
		 *@brief Método que busca una key en el map
		 *
		 *@param key Clave a buscar en el map
		 *
		 *@return true si se encontro la key en el map, en el caso contrario retorna false
		 */
		bool find(Key key);

		/**
		 *@brief Método que busca una kee en el map y mueve el cursor a esa posicion
		 *
		 *@param key Clave a buscar en el map
		 *
		 *@return true si se encontro la kye en el map, en el caso contrario retorna false
		 */
		bool search(Key key);

		/**
		 *@brief Método que nos deja ver la información de una couple
		 *
		 *@param _key Clave a buscar en el map
		 *
		 *@return La información de la couple asociada a la couple
		 */

		Value getValue(Key _key);

		/**
		 *@brief Método que retorna la couple a la que apunta el cursor de la DLL
		 *
		 *@return Apuntador de tipo Couple
		 */

		Couple<Key,Value> *getCursor();

		/**
		 *@brief Método que vacía el map
		 */

		void MakeEmpty();

};


//====================================Métodos privados============================================
template<typename Key, typename Value>
bool Map<Key,Value>::compareCouple(Couple<Key,Value>* key1, Couple<Key,Value>* key2){
	return key1 -> getKey() == key2 ->getKey();
}
//================================================================================================
template<typename Key, typename Value>
Map<Key,Value>::Map(){

	/*Se crea la tabla*/
	map = new DLL<Couple<Key,Value>*>();
}

template<typename Key, typename Value>
Map<Key,Value>::~Map(){

	/*Eliminamos la tabla*/
	delete map;
}

template<typename Key, typename Value>
void Map<Key,Value>::insert(Key _key,Value _value){

	/*Creamos la couple a insertar*/
	map ->InsertBack(new Couple<Key,Value>(_key,_value));
}

template<typename Key, typename Value>
bool Map<Key,Value>::remove(Key _key, Value *_data_back){

	bool done = false;
	Couple<Key,Value> *tmp = new Couple<Key,Value>(_key);
	
	/*Busca si existe la couple en el map*/
	if(map -> Search(tmp,compareCouple)){
		
		/*Elimian la couple*/
		map ->Remove(&tmp);

		/*Guarda el value de la couple*/
		*_data_back = tmp ->getValue();
		done = true;
	}

	/*Devolvemos la memoria de tmp*/
	delete tmp;

	return done;
}

template<typename Key, typename Value>
DLL<Couple<Key,Value>*> *Map<Key,Value>::getMap(){
	
	return map;
}

template<typename Key, typename Value>
bool Map<Key,Value>::find(Key key){
	bool done;

	/*Couple temporal para poder realizar la busqueda en la DLL*/
	Couple<Key,Value> *tmp = new Couple<Key,Value>(key);

	/*Vemos si esta la couple en la DLL*/
	done = map -> FindIf(tmp,compareCouple);

	/*Devolvemos la memoria solicitada para el tmp*/
	delete tmp;

	return done;
}

template<typename Key, typename Value>
bool Map<Key,Value>::search(Key key){

	bool done;

	/*Couple temporal para poder realizar la busqueda en la DLL*/
	Couple<Key,Value> *tmp = new Couple<Key,Value>(key);

	/*Vemos si esta la couple en la DLL*/
	done = map -> Search(tmp,compareCouple);

	/*Devolvemos la memoria solicitada de tmp*/
	delete tmp;

	return done;
}

template<typename Key, typename Value>
Value Map<Key,Value>::getValue(Key _key){

	/*Couple temporal para poder realizar la busqueda en la DLL*/
	Couple<Key,Value> *tmp = new Couple<Key,Value>(_key); 

	/*Variable que ayuda a no tener fugas de memoria*/
	Value retVal;

	if(map -> Search(tmp,compareCouple)){
		map ->Peek(&tmp);

		/*Guardamos el value aosiciado a la key buscada*/
		retVal = tmp ->getValue();

		/*Devolvemos la memoria solicitada para tmp*/
		delete tmp;
	}

	return retVal;
}

template<typename Key, typename Value>
Couple<Key,Value>* Map<Key,Value>::getCursor(){

	/*Couple para guardar la dirección de la couple de la DLL*/
	Couple<Key,Value>* tmp;

	/*Guardamos la dirección de la couple en la DLL*/
	map ->Peek(&tmp);

	return tmp;

}

template<typename Key, typename Value>
void Map<Key,Value>::MakeEmpty(){
	
	map ->MakeEmpty();
}

#endif