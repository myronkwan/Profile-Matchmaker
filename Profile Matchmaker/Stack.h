/*
copy insert, delete and listlength functions from LinkedList class and convert to pop,push,and isempty function.
Only changes to the functions to make them pop and push is set position of insertion/deletion to 1.
isemtpy changed to return 1 or 0 whether the list is empty or not.
*/

#ifndef STACKS_H
#define STACKS_H
#include <iostream>
#include "List.h"

using namespace std;

template<class T>
class Stack : public linkedlist<T>
{
protected:
	linkedlist<T>* listptr;
public:
	Stack();
	void push(T);
	void pop();
	int length();
	void print();
	T peek();
};
template<class T>
Stack<T>::Stack()
{
	listptr = new linkedlist<T>;
}
template<class T>
void Stack<T>::push(T z)//stack push
{
	insert(z, 1);
}
template <class T>
void Stack<T>::pop()
{
	deletenode(1);
}
template<class T>
int Stack<T>::length()
{
	return listlength();
}
template<class T>
void Stack<T>::print()
{
	while (listptr)
	{
		cout << listptr->headptr->data << "-->";
		pop();
	}
	cout << "NULL" << endl;

}

template<class T>
T Stack<T>::peek()
{
	if (length())
		return getHeadptr()->getnext()->getdata();
}

#endif