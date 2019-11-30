#ifndef STACK_HPP
#define STACK_HPP
#include "DLL.hpp"
#include <assert.h>

template <class Item>
class Stack{
	private:
		DLL<Item> *stack;
	public:
		Stack();
		~Stack();
		void Push(Item _data);
		Item Pop();
		Item Peek();
		bool IsEmpty();
		size_t Len();
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

	stack -> CursorFirst();

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

