#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "List_Node.h"

template <class T>
class LinkedList { //linked list class
protected:
	ListNode<T> *head; //head pointing node
public:
	LinkedList<T>() { head = nullptr; } //linked list constructor
	~LinkedList<T>(){}; //linked list destructor
	void appendNode(T); //new list
	void insertNode(T); //add anywhere
	void deleteNode(T); //delete anywhere
	ListNode<T>* findNode(T); //find anywhere
	void emptyList(); //empty the list
	int countNode(); //count the items in list
	void displayList() const; //show items in list
	ListNode<T>* getHead(){ return head; }//
};

template <class T>
void LinkedList<T>::appendNode(T new_data){ //new list function
	ListNode<T>* nodeptr;
	ListNode<T>* newNode;
	ListNode<T>* previousNode = nullptr;
	newNode = new ListNode<T>;

	newNode->data = new_data;
	if (!head)
		head = newNode;
	else {
		nodeptr = head;
		while (nodeptr){
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		previousNode->next = newNode;
	}

	return;
}

template <class T>
void LinkedList<T>::insertNode(T new_data){ //add anywhere function
	ListNode<T>* nodeptr;
	ListNode<T>* newNode;
	ListNode<T>* previousNode = nullptr;
	newNode = new ListNode<T>;
	newNode->data = new_data;

	if (!head)
		head = newNode;
	else {
		nodeptr = head;
		while (nodeptr && nodeptr->data < new_data){
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (previousNode == nullptr){
			head = newNode;
			newNode->next = nodeptr;
		}
		else{
			previousNode->next = newNode;
			newNode->next = nodeptr;
		}
	}
	return;
}

template <class T>
void LinkedList<T>::deleteNode(T new_data){ //delete anywhere
	ListNode<T>* nodeptr;
	ListNode<T>* previousNode = nullptr;

	nodeptr = head;
	while (nodeptr && nodeptr->data != new_data){
		previousNode = nodeptr;
		nodeptr = nodeptr->next;
	}

	if (previousNode == nullptr){
		nodeptr = head->next;
		delete head;
		head = nodeptr;
	}
	else if (nodeptr->data == new_data) {
		previousNode->next = nodeptr->next;
		delete nodeptr;
	}

	return;
}

template <class T>
int LinkedList<T>::countNode() { //count the items in list
	ListNode<T>* nodeptr;
	int count = 0;

	nodeptr = head;
	while (nodeptr){
		count++;
		nodeptr = nodeptr->next;
	}

	return count;
}

template <class T>
void LinkedList<T>::emptyList() { //empty the list
	ListNode<T>* previousNode = nullptr;
	ListNode<T>* nodeptr;

	nodeptr = head;
	if (!head)
		return;
	while (nodeptr){
		previousNode = nodeptr;
		nodeptr = nodeptr->next;
		delete previousNode;
	}

	return;
}

template <class T>
ListNode<T>* LinkedList<T>::findNode(T new_data) { //find anywhere
	ListNode<T>* nodeptr;
	ListNode<T>* previousNode = nullptr;

	nodeptr = head;
	while (nodeptr && nodeptr->data != new_data){
		nodeptr = nodeptr->next;
	}


	if (!nodeptr)
		return nullptr;
	else if (nodeptr->data == new_data) {
		return nodeptr;
	}
}

template <class T>
void LinkedList<T>::displayList() const{ //show items in list
	ListNode<T>* nodeptr;

	nodeptr = head;
	while (nodeptr){
		cout << nodeptr->data << ", ";
		nodeptr = nodeptr->next;
	}

	return;
}
#endif