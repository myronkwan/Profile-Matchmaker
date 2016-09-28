#ifndef _BST
#define _BST
#include"Tree_Node.h"
#include"Queue.h"
#include"profile.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

template <class T>
class Binary_Search_Tree {
protected:
	TreeNode<T> *root;
	void post_order_traversal(TreeNode<T>*);
	void in_order_traversal(TreeNode<T>*);
	void breadth_first_traversal(TreeNode<T>*);
	TreeNode<T>* find_node(const T&, TreeNode<T>*);
	TreeNode<T>* find_largest(TreeNode<T>* node);
	TreeNode<T>* find_smallest(TreeNode<T>* node);
	int get_height(TreeNode<T>* node);
	int get_number_of_nodes(TreeNode<T>* node);
	void print_tree(TreeNode<T>* node, int indent);

public:
	Binary_Search_Tree(){ root = nullptr; }
	Binary_Search_Tree(Stack<T>* undoPtr){ root = nullptr;  undoStack = undoPtr; }//
	void insertBST(T*);
	//void input_from_file(ifstream&);
	void post_order_traversal(){ post_order_traversal(root); }
	void in_order_traversal(){ in_order_traversal(root); }
	void breadth_first_traversal(){ breadth_first_traversal(root); }
	T searchByUsername(string username);//
	TreeNode<T>* find_node(const T& target){ return find_node(target, root); }
	TreeNode<T>* find_largest(){ return find_largest(root); }
	TreeNode<T>* find_smallest(){ return find_smallest(root); }
	bool deleteBST(T&);//
	bool isEmpty();
	int get_height(){ return get_height(root); }
	int get_number_of_nodes(){ return get_number_of_nodes(root); }
	T* match_profile(T& target);
	T* match_profile_2(T& target);
	void print_tree(){ return print_tree(root, 0); }
};

template<class T>
void Binary_Search_Tree<T>::print_tree(TreeNode<T>* node, int indent)
{
	if (node != NULL) {
		if (node->right) {
			print_tree(node->right, indent + 4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (node->right) std::cout << " /\n" << std::setw(indent) << ' ';
		std::cout <<= *(node->data);
		cout << "\n ";
		if (node->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			print_tree(node->left, indent + 4);;
		}
	}
}


template <class T>
void Binary_Search_Tree<T>::insertBST(T* new_data){
	TreeNode<T>* newNode;

	newNode = new TreeNode<T>;
	newNode->data = new_data;

	if (!root)
	{
		root = newNode;
	}
	else{
		TreeNode<T>* pWalk = root;
		TreeNode<T>* pParent = nullptr;

		while (pWalk){
			pParent = pWalk;
			if (*new_data<*(pWalk->data))
				pWalk = pWalk->left;
			else
				pWalk = pWalk->right;
		}

		if (*new_data<*(pParent->data))
			pParent->left = newNode;
		else
			pParent->right = newNode;

	}
	return;
}

/*template <class T>
void Binary_Search_Tree<T>::input_from_file(ifstream& input){
T new_data;

while (input.good()){
input >> new_data;
insertBST(new_data);
}
return;
}*/

template <class T>
void Binary_Search_Tree<T>::post_order_traversal(TreeNode<T>* node){
	if (!node)
		return;
	post_order_traversal(node->left);
	post_order_traversal(node->right);
	cout << node->data->getUsername();
	cout << endl;
	return;
}

template <class T>
void Binary_Search_Tree<T>::in_order_traversal(TreeNode<T>* node){
	if (!node)
		return;
	in_order_traversal(node->left);
	cout << *(node->data);
	cout << endl;
	in_order_traversal(node->right);
	return;
}



template <class T>
TreeNode<T>* Binary_Search_Tree<T>::find_largest(TreeNode<T>* node){
	if (!node)
		return node;
	else{
		TreeNode<T>* pWalk = node;
		while (pWalk->right)
			pWalk = pWalk->right;

		return pWalk;
	}
}

template <class T>
TreeNode<T>* Binary_Search_Tree<T>::find_smallest(TreeNode<T>* node){
	if (!node){
		return node;
	}

	else{
		TreeNode<T>* pWalk = node;

		while (pWalk->left)
			pWalk = pWalk->left;

		return pWalk;
	}
}

template <class T>
void Binary_Search_Tree<T>::breadth_first_traversal(TreeNode<T>* node){
	Queue<TreeNode<T>*> q;
	if (!node)
		return;
	else{
		q.enqueue(node);
		TreeNode<T>* pWalk;
		while (!q.isEmpty()){
			pWalk = q.peekFront();
			q.dequeue();
			if (pWalk->left)//
				q.enqueue(pWalk->left);
			if (pWalk->right)//
				q.enqueue(pWalk->right);
			cout << *(pWalk->data);
			cout << endl;
		}
	}
	return;
}

/*template <class T>//
T Binary_Search_Tree<T>::searchByUsername(string username)
{
Queue<TreeNode<T>*> q;
TreeNode<T>* node = root;
Profile dummyProfile;//returned when no profile is found

if (!node)
cout << "\nUser Not Found!";
else{
q.enqueue(node);
TreeNode<T>* pWalk;
while (!q.isEmpty()){
pWalk = q.peekFront();
q.dequeue();
if (pWalk->left)//
q.enqueue(pWalk->left);
if (pWalk->right)//
q.enqueue(pWalk->right);
if (pWalk->data.getUsername() == username)
{
return pWalk->data;
}
}
}

return dummyProfile;
}*/

/*template <class T>
bool Binary_Search_Tree<T>::deleteBST( T& target_data){

if (!root)
return 0;

else{
TreeNode<T>* pWalk = root;
TreeNode<T>* pParent = nullptr;

while (pWalk){

if (target_data < *(pWalk->data)){
pParent = pWalk;
pWalk = pWalk->left;
}
else if (*(pWalk->data) < target_data){
pParent = pWalk;
pWalk = pWalk->right;
}

else {
if (!pWalk->left){
if (pWalk == pParent->left)
pParent->left = pWalk->right;
else
pParent->right = pWalk->right;
}

else if (!pWalk->right){
if (pWalk == pParent->left)
pParent->left = pWalk->left;
else
pParent->right = pWalk->left;
}

else{
TreeNode<T>* pNode = find_largest(pWalk->left);
TreeNode<T>* Node = new TreeNode<T>;

Node->data = pNode->data;

if (pWalk == pParent->left)
pParent->left = Node;
else
pParent->right = Node;

Node->left = pWalk->left;
Node->right = pWalk->right;
delete pNode;
}
delete pWalk;
return 1;
}

}
return 0;
}
}*/

template <class T>
bool Binary_Search_Tree<T>::deleteBST(T& target_data){
	if (!root)
		return 0;

	else{
		TreeNode<T>* pWalk = root;
		while (pWalk){
			if (target_data < *(pWalk->data))
				pWalk = pWalk->left;

			else if (*(pWalk->data) < target_data)
				pWalk = pWalk->right;

			else{
				if (!pWalk->left && !pWalk->right){
					//delete pWalk->data;
					delete pWalk;
					return 1;
				}

				else if (pWalk->left && pWalk->right){
					TreeNode<T>* pNode = find_largest(pWalk->left);
					//delete pWalk->data;
					pWalk->data = pNode->data;
					delete pNode;
					return 1;
				}

				else if (pWalk->left){
					//delete pWalk->data;
					TreeNode<T>* pNode = pWalk->left;
					pWalk->data = pNode->data;
					pWalk->left = pNode->left;
					pWalk->right = pNode->right;
					delete pNode;
					return 1;
				}

				else if (pWalk->right){
					//delete pWalk->data;
					TreeNode<T>* pNode = pWalk->right;
					pWalk->data = pNode->data;
					pWalk->left = pNode->left;
					pWalk->right = pNode->right;
					delete pNode;
					return 1;
				}
			}
		}

		return 0;
	}
}

template <class T>
bool Binary_Search_Tree<T>::isEmpty(){
	if (!root)
		return 1;
	else
		return 0;
}

template <class T>
TreeNode<T>* find_node(const T& target, TreeNode<T>* node){
	if (!node)
		return nullptr;
	else{
		if (target < *(node->data))
			return find_node(target, node->left);
		else if (*(node->data) < target)
			return find_node(target, node->right);
		else
			return node;
	}
}

template <class T>
int Binary_Search_Tree<T>::get_height(TreeNode<T>* node){
	if (!node)
		return 0;
	else{
		int l, r;
		l = get_height(node->left);
		r = get_height(node->right);
		if (l > r)
			return l + 1;
		else
			return r + 1;
	}
}

template <class T>
int Binary_Search_Tree<T>::get_number_of_nodes(TreeNode<T>* node){
	if (!node)
		return 0;
	else{
		return 1 + get_number_of_nodes(node->left) + get_number_of_nodes(nodes->right);
	}
}

/*
template <class T>
void Binary_Search_Tree<T>::print_tree()
{

if (!root)
return;
else{

int h = get_height();
int s = 0;
int i = 0;
while (i < h){
s += pow(2, i);
i++;
}
int max = 6 * pow(2, h - 1);
int depth = s - pow(2, h - 1);
T** scores = new T*[s];

Queue<TreeNode<T>*> q;
q.enqueue(root);
TreeNode<T>* pWalk;
TreeNode<T>* dummy = new TreeNode<T>;
dummy->data = new T;

i = 0;

while (!q.isEmpty()){
pWalk = q.peekFront();
q.dequeue();
if (pWalk->left)//
q.enqueue(pWalk->left);
else if (i < depth)
q.enqueue(dummy);
if (pWalk->right)//
q.enqueue(pWalk->right);
else if (i < depth)
q.enqueue(dummy);

scores[i] = pWalk->data;

i++;
}

i = 0;
int indent1, indent2;
int n, m;
indent1 = 6 * (pow(2, h - 2) - 1) + 3;
indent2 = 6 * (pow(2, h - 1) - 1) + 1;
n = pow(2, 0);
m = pow(2, 0);
for (int j = 1; j <= h; j++){
if (j != h)
cout << setw(indent1) << ' ';
while (i < n){
if (scores[i] == dummy->data){
cout << "     " << setw(indent2) << ' ';
}
else{
cout << setw(5) <<= *(scores[i]);
cout << setw(indent2) << ' ';
}

i++;
}
cout << endl;
m = m * 2;
n = n + m;
indent2 = (indent2 + 5) / 2 - 5;
if (j != h - 1)
indent1 = (indent1 + 3) / 2 - 3;
}
}
}*/

/*
template <class T>
void Binary_Search_Tree<T>::print_tree(ofstream& output)
{
if (!root)
return;
else{
//output << "dllm" << endl;
int h = get_height();
//output << h << endl;
int s = 0;
int i = 0;
while (i < h){
s += pow(2, i);
i++;
}
int max = 6 * pow(2, h - 1);
int depth = s - pow(2, h - 1);
T** scores = new T*[s];

Queue<TreeNode<T>*> q;
q.enqueue(root);
TreeNode<T>* pWalk;
TreeNode<T>* dummy = new TreeNode<T>;
dummy->data = new T;

i = 0;

while (!q.isEmpty()){
pWalk = q.peekFront();
q.dequeue();
if (pWalk->left)//
q.enqueue(pWalk->left);
else if (i < depth)
q.enqueue(dummy);
if (pWalk->right)//
q.enqueue(pWalk->right);
else if (i < depth)
q.enqueue(dummy);

scores[i] = pWalk->data;

i++;
}

i = 0;
int indent1,indent2;
int n,m;
indent1 = 6 * (pow(2, h - 2) - 1) + 3;
indent2 = 6 * (pow(2, h - 1) - 1) + 1;
n = pow(2, 0);
m = pow(2, 0);

//output << "dllm2" << endl;

for (int j = 1; j <= h; j++){
//output << "dllm3" << endl;
if (j!=h)
output << setw(indent1) << ' ';
while (i < n){
if (scores[i] == dummy->data){
output << "     " << setw(indent2) << ' ';
}
else{
output <<setw(5)<<= *(scores[i]);
output << setw(indent2)<<' ';
}

i++;
}
output << endl;
m = m * 2;
n = n + m;
indent2 = (indent2 + 5) / 2 - 5;
if (j != h - 1)
indent1 = (indent1 + 3) / 2 - 3;
}
}
}*/

template <class T>
T* Binary_Search_Tree<T>::match_profile(T& target){
	if (!root)
		throw "There is nothing in the database.";
	else if (!root->left && !root->right)
		return root->data;
	else{
		TreeNode<T>* pWalk = root;
		TreeNode<T>* pParent = nullptr;

		while (pWalk->left || pWalk->right){
			if (!(target<*(pWalk->data)) && !(*(pWalk->data)<target))
				return pWalk->data;

			if (pWalk->left && target<*(pWalk->data)){
				pParent = pWalk;
				pWalk = pWalk->left;
				continue;
			}
			if (!pWalk->left && target<*(pWalk->data))
				break;

			if (pWalk->right && *(pWalk->data)<target){
				pParent = pWalk;
				pWalk = pWalk->right;
				continue;
			}
			if (!pWalk->right&& *(pWalk->data)<target)
				break;
		}

		if (!pParent)
			return pWalk->data;

		else {
			int d1, d2;
			d1 = abs(pParent->data->getScore() - target.getScore());
			d2 = abs(pWalk->data->getScore() - target.getScore());
			if (d1<d2)
				return pParent->data;
			else
				return pWalk->data;
		}
	}
}

template <class T>
T* Binary_Search_Tree<T>::match_profile_2(T& target){
	if (!root)
		throw "There is nothing in the database.";
	else if (!root->left && !root->right)
		throw "There is only one person in the database.";
	else{
		TreeNode<T>* pWalk = root;
		TreeNode<T>* pParent = nullptr;

		while (*(pWalk->data) != target){
			if (*(pWalk->data)<target){
				pParent = pWalk;
				pWalk = pWalk->right;
			}
			else{
				pParent = pWalk;
				pWalk = pWalk->left;
			}
		}

		TreeNode<T>* l = nullptr;
		TreeNode<T>* r = nullptr;
		int d1, d2;

		if (!pParent){
			if (pWalk->left)
				l = find_largest(pWalk->left);
			if (pWalk->right)
				r = find_smallest(pWalk->right);
			if (!l && r)
				return r->data;
			else if (!r && l)
				return l->data;
			else{
				d1 = abs(l->data->getScore() - target.getScore());
				d2 = abs(r->data->getScore() - target.getScore());
				if (d1<d2)
					return l->data;
				else
					return r->data;
			}
		}

		else {
			int d3;
			if (pWalk->left)
				l = find_largest(pWalk->left);
			if (pWalk->right)
				r = find_smallest(pWalk->right);

			if (l && r){
				d1 = abs(l->data->getScore() - target.getScore());
				d2 = abs(r->data->getScore() - target.getScore());
				d3 = abs(pParent->data->getScore() - target.getScore());
				if (d1 <= d2 && d1 <= d3)
					return l->data;
				if (d2 <= d1 && d2 <= d3)
					return r->data;
				if (d3 <= d1 && d3 <= d2)
					return pParent->data;
			}
			else if (l && !r){
				d1 = abs(l->data->getScore() - target.getScore());
				d3 = abs(pParent->data->getScore() - target.getScore());
				if (d1 <= d3)
					return l->data;
				if (d3 <= d1)
					return pParent->data;
			}
			else if (!l && r){
				d2 = abs(r->data->getScore() - target.getScore());
				d3 = abs(pParent->data->getScore() - target.getScore());
				if (d2 <= d3)
					return r->data;
				if (d3 <= d2)
					return pParent->data;
			}
			else {
				return pParent->data;
			}
		}
	}
}







#endif