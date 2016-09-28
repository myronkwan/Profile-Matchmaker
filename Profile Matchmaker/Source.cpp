//nithin tommy yonas myron

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "Stack.h"
#include "profile.h"
#include "BST_Template.h"
#include "HashTable.h"
#include "HeadNode.h"

using namespace std;

void addProfile(HeadNode<Profile>* hn, LinkedList<Profile>* ul)
{
	Profile newprofile;
	Profile *ptemp = nullptr;

	cout << "\nAdding New Profile:";
	cin >> newprofile;
	if (hn->pHash->htable[hn->pHash->Hashfunction2(newprofile.getUsername())] != NULL)
	{
		if (hn->pHash->htable[hn->pHash->Hashfunction2(newprofile.getUsername())]->getdata()->getUsername() == newprofile.getUsername())
		{
			cout << "\nUser can't be added! Profile already Taken. Please re-try using different username.\n";
			system("pause");
			return;
		}
	}
	ul->appendNode(newprofile);
	ptemp = &(ul->findNode(newprofile)->data);
	hn->pHash->insert(ptemp);
	hn->pBST->insertBST(ptemp);
	hn->arrySize = ul->countNode();

}

Profile* createProfile(HeadNode<Profile>* hn, LinkedList<Profile>* ul)
{
	Profile newprofile;
	Profile *ptemp = nullptr;

	cout << "\nAdding New Profile:";
	cin >> newprofile;
	if (hn->pHash->htable[hn->pHash->Hashfunction2(newprofile.getUsername())] != NULL)
	{
		if (hn->pHash->htable[hn->pHash->Hashfunction2(newprofile.getUsername())]->getdata()->getUsername() == newprofile.getUsername())
		{
			cout << "\nUser can't be added! Profile already Taken. Please re-try using different username.\n";
			system("pause");
			return nullptr;
		}
	}
	ul->appendNode(newprofile);
	ptemp = &(ul->findNode(newprofile)->data);

	hn->pHash->insert(ptemp);
	hn->arrySize = ul->countNode();

	return ptemp;
}



int main() {
	int size = 5; //initial array size
	const int MAX = 100;
	int choice = 0;
	int n;//used for efficiency, n=size of userlist
	bool fail = true;//boolean for try catch loop
	LinkedList<Profile>* userlist = new LinkedList<Profile>;//create list of users dynamically
	fstream infile("input.txt", ios::in); //input file
	Stack<Profile>* undoPtr = new Stack<Profile>;//the undo stack
	Binary_Search_Tree<Profile>* pBST = new Binary_Search_Tree<Profile>;//BST tree pointer
	HashTable<Profile>* pHash = new HashTable <Profile>;
	HeadNode<Profile> headNode(pHash, pBST, undoPtr);

	Profile temp, *ptemp = nullptr;
	int count;

	while (infile)//read file to dynamic list 
	{
		infile >> temp;
		if (temp.getUsername() != "")
			userlist->appendNode(temp);//append to userlist 
	}
	infile.close();

	headNode.arrySize = userlist->countNode();

	//insert list node pointers to BST and HASHTABLE
	ListNode<Profile>* current = userlist->getHead();
	while (current){
		headNode.pBST->insertBST(&(current->data));
		headNode.pHash->insert(&(current->data));
		current = current->next;
	}

	do{
		system("cls");
		ptemp = nullptr;
		int key = 1;
		string info;
		Profile newprofile;

		cout << "\n\t\t********* Main Menu **********";
		cout << "\n\t (" << key++ << "). Add new data";
		cout << "\n\t (" << key++ << "). Delete data";
		cout << "\n\t (" << key++ << "). Find and display one data record using the primary key";
		cout << "\n\t (" << key++ << "). List data in Hash table sequence [#]";
		cout << "\n\t (" << key++ << "). List data in key sequence(sorted)";
		cout << "\n\t (" << key++ << "). Print indented tree " << char(5);
		cout << "\n\t (" << key++ << "). Efficiency";
		cout << "\n\t (" << key++ << "). MATCH MAKER " << char(2);
		cout << "\n\t (" << key++ << "). Save To File";
		cout << "\n\t(" << key++ << "). Quit";
		if (headNode.getUndoStack()->length())
			cout << "\n\t(" << key++ << "). Undo Deletion";
		cout << "\n\tENTER YOUR CHOICE: ";
		cin.sync(); cin.clear(); cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			addProfile(&headNode, userlist);
			/*cout << "\nAdding New Profile:";
			cin >> newprofile;
			if (headNode.pHash->htable[headNode.pHash->Hashfunction2(newprofile.getUsername())] != NULL)
			{
			if (headNode.pHash->htable[headNode.pHash->Hashfunction2(newprofile.getUsername())]->getdata()->getUsername() == newprofile.getUsername())
			{
			cout << "\nUser can't be added! Profile already Taken. Please re-try using different username.\n";
			system("pause");
			break;
			}
			}
			userlist->insertNode(newprofile);
			ptemp = &(userlist->findNode(newprofile)->data);
			headNode.pHash->insert(ptemp);
			headNode.pBST->insertBST(ptemp);
			headNode.arrySize = userlist->countNode();*/

			break;
		case 2:
			cout << endl;
			cout << "List of Usernames: " << endl;
			headNode.pBST->post_order_traversal();
			cout << "\nEnter Username to Delete: ";
			cin.sync(); cin.clear(); cin >> info;
			count = 0;

			try
			{

				ptemp = pHash->getprofile(info);
				headNode.pHash->remove(info);
				headNode.getUndoStack()->push(*ptemp);
				headNode.pBST->deleteBST(*ptemp);
				userlist->deleteNode(*ptemp);
				headNode.arrySize = userlist->countNode();
				cout << "\nUser Profile Deleted!\n";
				cout << headNode.getUndoStack()->peek();
			}
			catch (char* msg)
			{
				cout << msg;
			}

			system("pause>nul");
			break;
		case 3:
			cout << endl;
			cout << "List of Usernames: " << endl;
			headNode.pBST->post_order_traversal();

			cout << "\nEnter Username to View Profile: ";
			cin.sync(); cin.clear(); cin >> info;
			/*while (!ptemp && count<MAX)
			{
			if (headNode.pHash->htable[count] != NULL)
			if (headNode.pHash->htable[count]->getdata()->getUsername()==info)
			ptemp = headNode.pHash->htable[count]->getdata();
			count++;
			}*/
			try
			{
				ptemp = pHash->getprofile(info);
				cout << *ptemp;
			}

			catch (char* msg)
			{
				cout << msg;
			}
			system("pause");

			break;
		case 4:
			system("cls");
			cout << "\n\tPrint HASHTABLE Format\n";
			headNode.pHash->list();
			count = 0;

			system("pause");
			break;
		case 5:
			cout << "\n\tBST In order traversal:\n";
			headNode.pBST->in_order_traversal();
			system("pause");
			break;
		case 6:
			cout << "\n\tPrint Indented Tree Format\n";
			headNode.pBST->print_tree();
			system("pause>nul");
			break;
		case 7://need to make it clear screen
			n = userlist->countNode();
			cin.sync();
			cout << "\n\tProgram Efficiency Module\n" << endl << endl;

			cout << "\n\t Binary Search Tree:" << endl;
			cout << "\n\tAccess Efficiency: ";
			cout << "\n\t\t Average: O(log(" << n << "))" << "\t\t Worst: O(" << n << ")" << endl;
			cout << "\n\tDeletion Efficiency: ";
			cout << "\n\t\t Average: O(log(" << n << "))" << "\t\t Worst: O(" << n << ")" << endl;
			cout << "\n\tInsertion Efficiency: ";
			cout << "\n\t\t Average: O(log(" << n << "))" << "\t\t Worst: O(" << n << ")" << endl;
			cout << "\n\tSearch Efficiency: ";
			cout << "\n\t\t Average: O(log(" << n << "))" << "\t\t Worst: O(" << n << ")" << endl;

			cout << "\n\t HashTable with linear probing:" << endl;
			cout << "\n\tDeletion Efficiency: ";
			cout << "\n\t\t Average: O(1)" << "\t\t Worst: O(" << n << ")" << endl;
			cout << "\n\tInsertion Efficiency: ";
			cout << "\n\t\t Average: O(1)" << "\t\t Worst: O(" << n << ")" << endl;
			cout << "\n\tSearch Efficiency: ";
			cout << "\n\t\t Average: O(1)" << "\t\t Worst: O(" << n << ")" << endl;
			system("pause");
			break;
		case 8:
			char ch;
			cout << "\nPress (1) to match existing profile or (2) to match a new profile: ";

			while (fail){
				try {
					cin.sync();
					cin.clear();
					cin >> ch;
					if (ch != '1' && ch != '2')
						throw "Invalid input. Please enter either 1 or 2: ";
					else
						fail = false;
				}
				catch (char* error) {
					cout << error;
				}
			}
			fail = true;
			try{
				if (ch == '1')//option1 match existing profile
				{
					cout << endl;
					cout << "List of Usernames: " << endl;
					headNode.pBST->post_order_traversal();
					cout << "\nEnter Username to get Matching Profile(s): ";
					cin.sync(); cin.clear(); cin >> info;
					ptemp = pHash->getprofile(info);
					cout << endl;
					if ((headNode.pBST->match_profile_2(*ptemp))->getUsername() != "")
						cout << *(headNode.pBST->match_profile_2(*ptemp));
					cout << *ptemp;
				}
				else if (ch == '2')	//options 2 make profile and find match
				{
					//please use match_profile() to do option2
					ptemp = createProfile(&headNode, userlist);
					cout << endl;
					if (ptemp){
						system("cls");
						cout << "\nMatching Profile(s)\n" << endl;
						cout << *(headNode.pBST->match_profile(*ptemp));
						cout << *ptemp;
						headNode.pBST->insertBST(ptemp);
					}
				}
			}
			catch (char* msg)
			{
				cout << msg;
			}
			system("pause");
			break;
		case 9:
			cout << "Saving user list to file..." << endl;
			infile.open("input.txt", ios::out);
			current = userlist->getHead();
			while (current){
				infile << current->data;
				current = current->next;
			}
			infile.close();
			cout << "Saved to file!" << endl;
			while (headNode.getUndoStack()->length())//delete undo stack
				headNode.getUndoStack()->pop();

			system("PAUSE");
			break;
		case 10:
			choice = 0;
			break;
		case 11:
			if (headNode.getUndoStack()->length())
			{
				count = 0;
				while (!ptemp && count < MAX)
				{
					if (headNode.pHash->htable[count] != NULL)
						if (headNode.pHash->htable[count]->getdata()->getUsername() == headNode.getUndoStack()->peek().getUsername())
						{
							//cout << "\nCan't Undo! A new profile with the same username already Exist.\n";
							headNode.getUndoStack()->pop();
							//system("pause");
							break;
						}
					count++;
				}
				userlist->insertNode(headNode.getUndoStack()->peek());
				ptemp = &((userlist->findNode(headNode.getUndoStack()->peek()))->data);
				headNode.pHash->insert(ptemp);
				headNode.pBST->insertBST(ptemp);
				headNode.arrySize = userlist->countNode();
				headNode.getUndoStack()->pop();
			}
			break;
		default:
			choice = 12;
			break;
		}

	} while (choice);

	//cout << "\n\tList Content:\n";
	//userlist->displayList();

	cout << "Saving user list to file..." << endl;
	infile.open("input.txt", ios::out);
	current = userlist->getHead();
	while (current){
		infile << current->data;
		current = current->next;
	}
	infile.close();
	cout << "Saved to file!" << endl;
	system("PAUSE");

	return 0;
}