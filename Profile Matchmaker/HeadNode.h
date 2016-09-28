#ifndef _HEADNODE
#define _HEADNODE
#include "Stack.h"
#include "BST_Template.h"
#include "HashTable.h"
template <class T>
class HeadNode {
	Stack<T>* undoStack;
public:
	HashTable<T>* pHash;
	Binary_Search_Tree<T>* pBST;
	int count;
	int arrySize;
	void setUndoStack(Stack<T>* undo){ undoStack = undo; }
	Stack<T>* getUndoStack(){ return undoStack; }
	HeadNode(HashTable<T>* pH, Binary_Search_Tree<T>* pB, Stack<T>* pS){ pHash = pH; pBST = pB; undoStack = pS; }
};

#endif