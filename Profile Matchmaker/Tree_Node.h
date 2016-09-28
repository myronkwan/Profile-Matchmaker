#ifndef _TREE_NODE
#define _TREE_NODE
#include "Stack.h"
template <class T>
struct TreeNode {
	T* data;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
};

#endif