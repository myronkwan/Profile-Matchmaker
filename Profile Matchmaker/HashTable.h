#ifndef HASTABLE_H
#define HASTABLE_H
#include <iostream>
#include "NODE.h"
#include "profile.h"
#include <string>
using namespace std;

template <class T>
class HashTable
{

public:
	Node<T>** htable;//
	HashTable();
	~HashTable();
	int Hashfunction(Profile*);//accepts Profile returns the hash value for use in insert function
	int Hashfunction2(string);
	void insert(Profile*);
	void remove(string);//accepts string of username to remove
	int search();
	Profile* getprofile(string);//accepts int key
	void list();
};

template <class T>
HashTable<T>::HashTable()
{
	htable = new Node<T>*[100];//default at size 20
	for (int i = 0; i < 100; i++)
	{
		htable[i] = NULL;//set all linked lists to start with pointing to NULL
	}
}



template <class T>
HashTable<T>::~HashTable()//size of hashtable
{
	for (int i = 0; i < sizeof(htable); ++i)
	{
		Node* entry = htable[i];
		while (entry != NULL)
		{
			Node*prev = entry;
			entry->setnext(entry);
			delete prev;
		}
	}
	delete[] htable;
}

template <class T>
int HashTable<T>::Hashfunction(Profile* subj)//accepts Profile pointer,makes key using ascii values of the username
{

	int key = 0;
	for (int i = 0; i < subj->getUsername().length(); i++)
	{
		key += subj->getUsername()[i];
	}
	return (key % 100);
}

template <class T>
int HashTable<T>::Hashfunction2(string subj)//accepts string from search,returns key to search
{

	int key = 0;
	for (int i = 0; i < subj.length(); i++)
	{
		key += subj[i];
	}
	return (key % 100);
}

template <class T>
void HashTable<T>::insert(Profile* subj)//accepts Profile to be inserted
{
	int hashvalue = Hashfunction(subj);
	cout << "object has hash: " << hashvalue << endl;

	if (htable[hashvalue] == NULL)//once u get to null node
	{
		htable[hashvalue] = new Node<T>(subj);

		cout << "node as been set." << endl;
	}
	else//linear probing
	{
		cout << "index is full, finding new index" << endl;
		int i = 0;
		while (htable[hashvalue + i] != NULL&& hashvalue + i <100)//linear probing
		{
			i++;
		}
		if (htable[hashvalue + i] == NULL)
		{
			htable[hashvalue + i] = new Node<T>(subj);
			cout << "node set at: " << hashvalue + i << endl;
		}
		else//if null node cant be found, start searching for one from the beginning of the array
		{
			i = 0;
			while (htable[i] != NULL&& i != hashvalue)
			{
				i++;
			}
			if (htable[i] == NULL)
			{
				htable[i] = new Node<T>(subj);
				cout << "node set at: " << i << endl;
			}
			else//else if no NULL node is found and you get back to original hash index, then no more memory in hash table
			{
				cout << "No more memory to store profile." << endl;
			}
		}
	}

}

template <class T>
void HashTable<T>::remove(string username)//start at the hash index, and iterate until found
{
	int hashvalue = Hashfunction2(username);//if hash index is NULL, getdata() will crash system
	int i = 0;
	while (htable[hashvalue + i] != NULL)//if there is something stored at the hash
		//START SEARCH AT THE HASH INDEX TO SAVE TIME INSTEAD OF STARTING SEARCH AT THE BEGINNING OF THE ARRAY
	{
		if (htable[hashvalue + i]->getdata()->getUsername() == username)//if username matches, delete profile
		{
			//delete htable[hashvalue + i];
			htable[hashvalue + i] = NULL;
			//cout << "Profile has been deleted." << endl;
			return;
		}
		else if (htable[hashvalue + i] == NULL)//else if node is null, profile isnt found
		{
			//cout << "Profile was not found." << endl;
			return;
		}
		else if (hashvalue + i == sizeof(htable))//else if you iterated until the end of the array, then start at the begiining and search the ones you skipped
		{

			i = 0;
			while (htable[i] != NULL)//go to beginning of array and iterate through the profiles before the hashindex
			{

				if (htable[i]->getdata()->getUsername() == username)//if match delete
				{
					//delete htable[i];
					htable[i] = NULL;//is this the proper way to delete?
					//cout << "Profile has been deleted." << endl;
					return;
				}
				else if (htable[i] == NULL)//else if null is found before the profile u want then its not there
				{
					//cout << "Profile was not found." << endl;
					return;
				}
				else if (i == hashvalue)//else if u iterate until u get back to hashindex, then nothing is there
				{
					//cout << "Profile was not found." << endl;
					return;
				}
			}
		}
		i++;
	}

	//cout << "Profile was not found." << endl;//else hash index was null so nothing is there
}

template <class T>
int HashTable<T>::search()//just for testing the has table
{
	int hashvalue;
	cout << "Enter Hash value [int]: ";
	cin >> hashvalue;
	Node<T>* entry = htable[hashvalue];
	bool check = false;
	if (entry == NULL)
	{
		cout << "Profile was not found." << endl;

	}

	else
	{
		cout << *(entry->getdata()) << endl;
	}
	if (!check)
	{
		return -1;
	}
}
template <class T>
Profile* HashTable<T>::getprofile(string username)//returns data pointer to profile, otherwise throws exception.
{
	int hashvalue = Hashfunction2(username);

	int i = 0;
	while (htable[hashvalue + i] != NULL)//if there is something stored at the hash
		//START SEARCH AT THE HASH INDEX TO SAVE TIME INSTEAD OF STARTING SEARCH AT THE BEGINNING OF THE ARRAY
	{
		if (htable[hashvalue + i]->getdata()->getUsername() == username)//if username matches, delete profile
		{

			return htable[hashvalue + i]->getdata();
		}
		else if (htable[hashvalue + i] == NULL)//else if node is null, profile isnt found
		{
			throw "Profile was not found.\n";

		}
		else if (hashvalue + i == sizeof(htable))//else if you iterated until the end of the array, then start at the begiining and search the ones you skipped
		{

			i = 0;
			while (htable[i] != NULL)//go to beginning of array and iterate through the profiles before the hashindex
			{

				if (htable[i]->getdata()->getUsername() == username)//if match delete
				{

					return htable[i]->getdata();
				}
				else if (htable[i] == NULL)//else if null is found before the profile u want then its not there
				{
					throw "Profile was not found.\n";
				}
				else if (i == hashvalue)//else if u iterate until u get back to hashindex, then nothing is there
				{
					throw "Profile was not found.\n";
				}
			}
		}
		i++;
	}

	throw "Profile was not found.\n";
}

template <class T>
void HashTable<T>::list()//iterates through all elements
{
	for (int i = 0; i < 100; i++)
	{
		if (htable[i] != NULL)
		{
			cout << "Profile stored at key: " << i << endl;
			cout << *(htable[i]->getdata());
		}
	}
}

#endif 