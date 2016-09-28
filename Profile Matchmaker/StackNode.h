#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
using namespace std;

template <class T>
class SNODE
{
protected:
	T data;

	SNODE<T>* next;//pointer to next SNODE
	SNODE<T>* previous;

public:

	SNODE();
	SNODE(T);
	SNODE(int, T);
	void setdata(T);
	void setnext(SNODE<T>*);
	void setprevious(SNODE<T>*);
	T getdata();
	SNODE<T>* getnext();
	SNODE<T>* getprevious();

};
template <class T>
SNODE<T>::SNODE(){}

template <class T>
SNODE<T>::SNODE(T d)
{
	setdata(d);
}


template <class T>
void SNODE<T>::setdata(T z)
{
	data = z;
}

template <class T>
void SNODE<T>::setnext(SNODE<T>* newSNODE)
{
	next = newSNODE;
}
template <class T>
void SNODE<T>::setprevious(SNODE<T>* newSNODE)
{
	previous = newSNODE;
}
template <class T>
T SNODE<T>::getdata()
{
	return data;
}
template <class T>
SNODE<T>* SNODE<T>::getnext()
{
	return next;
}
template <class T>
SNODE<T>* SNODE<T>::getprevious()
{
	return previous;
}


#endif
