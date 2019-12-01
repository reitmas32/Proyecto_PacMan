/**!<Guardas de inclusión*/
#ifndef STACK_HPP
#define STACK_HPP

/**!<Bibliotecas necesarias*/
#include "DLL.hpp"
#include <assert.h>

/**
 *@class Stack
 *@brief Representa una pila
 */
template <class Item>
class Stack{
	private:
		/**!<Lista que contendra los datos*/
		DLL<Item> *stack;
	public:
		/**
		 *@brief Método cosntructor de la stack
		 */
		Stack();

		/**
		 *@brief Método destructor de la stack
		 */
		~Stack();

		/**
		 *@brief Método que ingresa un elemento a la stack
		 *
		 *@param _data Elemento a ingresar en al stack
		 */
		void Push(Item _data);

		/**
		 *@brief Método que saca un elemento de la stack
		 *
		 *@return Ultimo elemento ingresado en la stack
		 */
		Item Pop();

		/**
		 *@brief Método que nos permite ver el ultimo elemento ingresado a la stack
		 *
		 *@return Ultimo elemento ingresado en la stack
		 */
		Item Peek();

		/**
		 *@brief Método que ve si la stack esta vacía
		 *
		 *@return True si esta vacía, en caso contrario retorna false
		 */
		bool IsEmpty();

		/**
		 *@brief Método que nos dice el numero de elementos en la stack
		 *
		 *@return Numero de elemento en la stack
		 */
		size_t Len();

		/**
		 *@brief Método que vaía la stack
		 */
		void MakeEmpty();

};

template <class Item>
Stack<Item>::Stack(){
	stack = new DLL<Item>();
}

template <class Item>
Stack<Item>::~Stack(){
	delete stack;
}

template <class Item>
void Stack<Item>::Push(Item _data){

	stack -> InsertFront(_data);
}

template <class Item>
Item Stack<Item>::Pop(){
	assert(!stack -> IsEmpty());

	Item retVal;

	stack -> RemoveFront(&retVal);

	return retVal;
}

template <class Item>
Item Stack<Item>::Peek(){

	assert(!stack -> IsEmpty());

	Item retVal;

	/*Movemos el cursor de DLL al primer elemento*/
	stack -> CursorFirst();

	/*Observamso el primer elemento de la DLL*/
	stack -> Peek(&retVal);

	return retVal;
}

template <class Item>
bool Stack<Item>::IsEmpty(){

	return stack -> IsEmpty();
}

template <class Item>
size_t Stack<Item>::Len(){
	return stack ->Len();
}

template <class Item>
void Stack<Item>::MakeEmpty(){
	stack ->MakeEmpty();
}
#endif

