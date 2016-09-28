#ifndef _QUEUE
#define _QUEUE
#include "Linked_List.h"

template<class T>
class Queue :private LinkedList<T> { //queue class inherited from linked list
private:
	ListNode<T> *tail; //tail pointing node
public:
	Queue<T>() : LinkedList<T>(){ tail = nullptr; }; //queue constructor
	~Queue<T>(){}; //queue destructor
	void enqueue(T); //enqueue function adds to tail of list
	void dequeue(); //dequeue function removes from head of list
	T peekFront(); //peekFront returns front node
	T peekRear(); //peekFront returns rear node
	bool isEmpty(); //isEmpty returns whether or not queue is empty
	void displayQueue(); //show items in list
	void emptyQueue(); //empties the whole queue

};

template <class T> //template so it works with any data type
void Queue<T>::enqueue(T new_data) { //enqueue function
	ListNode<T> *newNode; //new node

	newNode = new ListNode<T>; //allocate memory for new node
	newNode->data = new_data; //assign data from what user input in main
	newNode->next = nullptr; //point to null so it'll be new tail

	if (!head && !tail) //make it the head and tail if queue is empty
		head = tail = newNode;
	else {
		tail->next = newNode; //point current tail node to new node
		tail = newNode; //make new node the new tail
	}

	return;
}

template <class T>
void Queue<T>::dequeue() { //dequeue function
	ListNode<T> *nodeptr = head; //make nodepointer point to head

	if (!head && !tail) //don't dequeue if queue is empty
		return;
	else if (head == tail) //if there's only one node, make head and tail point to null
		head = tail = nullptr;
	else //if there's more than one node, point head pointer to the next one
		head = head->next;

	delete nodeptr; //delete previous node
}

template <class T>
T Queue<T>::peekFront() { //peekFront function
	return head->data; //return data from front node of queue
}

template <class T>
T Queue<T>::peekRear() { //peekRear function
	return tail->data; //return data from rear node of queue
}

template <class T>
bool Queue<T>::isEmpty() { //isEmpty function
	if (!head && !tail)
		return 1; //return 1 if empty (no head or tail)
	else
		return 0; //return 0 if not empty
}

template <class T>
void Queue<T>::displayQueue() { //show items in list
	/*ListNode<T>* nodeptr;

	nodeptr = head;
	while (nodeptr){
	cout << nodeptr->data << ", ";
	nodeptr = nodeptr->next;
	}

	return;*/
	displayList();
}

template <class T>
void Queue<T>::emptyQueue() { //empty the list
	while (head != nullptr) {
		ListNode<T> *nodeptr = head; //make nodepointer point to head

		if (!head && !tail) //don't dequeue if queue is empty
			return;
		else if (head == tail) //if there's only one node, make head and tail point to null
			head = tail = nullptr;
		else //if there's more than one node, point head pointer to the next one
			head = head->next;

		delete nodeptr; //delete previous node
	}
}

#endif
