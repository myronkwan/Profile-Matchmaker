#ifndef _LIST_NODE
#define _LIST_NODE
#include"Node.h"

template <class T>
struct ListNode {
	T data;
	ListNode* next = nullptr;
};

#endif
