#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
protected:
	T* data;
	Node<T>* next;//pointer to next node
	Node<T>* previous;

public:

	Node();
	Node(T*);
	void setdata(T*);
	void setnext(Node<T>*);
	void setprevious(Node<T>*);
	T* getdata();
	Node<T>* getnext();
	Node<T>* getprevious();
};
template <class T>
Node<T>::Node(){}

template <class T>
Node<T>::Node(T* d)
{
	setdata(d);
}

template <class T>
void Node<T>::setdata(T* z)
{
	data = z;
}

template <class T>
void Node<T>::setnext(Node<T>* newnode)
{
	next = newnode;
}
template <class T>
void Node<T>::setprevious(Node<T>* newnode)
{
	previous = newnode;
}
template <class T>
T* Node<T>::getdata()
{
	return data;
}
template <class T>
Node<T>* Node<T>::getnext()
{
	return next;
}
template <class T>
Node<T>* Node<T>::getprevious()
{
	return previous;
}

#endif