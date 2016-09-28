#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "StackNode.h"
using namespace std;

template<class T>
class linkedlist
{
protected:
	SNODE<T>* headptr;

public:

	int length;
	void printlist();
	void append(T);//adds to end of list,
	int locate(T);//return position, accept data
	void deletelist();
	SNODE<T>* getHeadptr(){ return headptr; }

	void insert(T, int);//also take in user input of position in list they want to insert, stack ovveride to insert to top of list only(dont use position input)
	void deletenode(int);//accept position to delete 
	int listlength();//ovveride in stack for isempty()

	linkedlist();
};
template <class T>
linkedlist<T>::linkedlist()
{
	headptr = new SNODE<T>;//creat a headSNODE and set headptr to point to the headSNODE
	length = 0;


}

/*printlist()
set temp to headptr
if temp->next ==NUll    (no data SNODE)

else				(there is dataSNODE)
point temp to first dataSNODE
do
print SNODE data
point temp to next SNODE
while temp != NULL   (there exist a SNODE that follows)
End Loop
print "NULL"
end if
end method
*/
template <class T>
void linkedlist<T>::printlist()
{
	SNODE<T>* temp = headptr;//temporary pointer

	if (temp->getnext() == NULL)//if only one SNODE in list(the head SNODE/no data SNODE)
	{
	}
	else//else if list has more than one SNODE
	{
		temp = temp->getnext();//skip reading out head SNODE;
		do
		{
			cout << temp->getdata() << "-->";
			temp = temp->getnext();
		} while (temp != NULL);
		cout << "NULL" << endl;
	}
}

/*append()
set z to parameter value
set newSNODE point to a new SNODE
set SNODE data to z
set SNODE.next point to NULL
set temp point to headSNODE

if headSNODE points to a data SNODE
while data SNODE points to other data SNODE
set temp point to next data SNODE
end loop

set data SNODE point to the new data SNODE
increment list length
else
set headSNODE point to new data SNODE
increment list length
end if

end method
*/
template <class T>
void linkedlist<T>::append(T z)
{
	SNODE<T>* newSNODE = new SNODE<T>();//create a new SNODE with constructor
	newSNODE->setdata(z);
	newSNODE->setnext(NULL);//set pointer to null since its new end of list

	SNODE<T>* temp = headptr;//temp pointer

	if (temp != NULL)//if SNODEs already in list
	{
		while (temp->getnext() != NULL)
		{
			temp = temp->getnext();//move temp pointer to last SNODE
		}
		temp->setnext(newSNODE);//sets last SNODE to point to new SNODE
		length++;
	}
	else//if no other SNODEs in list, set new SNODE as first thing in list
	{
		headptr->setnext(newSNODE);
		length++;
	}
}
/*insert()
set z to 1st par
set input to 2nd par
set newSNODE point to a newSNODE
set newSNODE data to z
set prev point to headSNODE
set current point to headSNODE
set position to 0

if headSNODE points to a dataSNODE
while current SNODE points to a dataSNODE and position < input
set prev to current
set current point to net SNODE
increment position
end loop
if position == 0
set current SNODE point to newSNODE
set newSNODE point to NULL
increment list length
else if current SNODE points to null position +1 == input
set current SNODE point to newSNODE
set newSNODE point to null
increment list length
else if position > input
prompte user attempt failed
else
set previous SNODE point to newSNODE
set newSNODE point to current SNODE
increment list length
end if

else
set headptr point to newSNODE
set newSNODE point to null
increment list length
end if

end method

*/
template <class T>
void linkedlist<T>::insert(T z, int input)
{
	SNODE<T>* newSNODE = new SNODE<T>();
	newSNODE->setdata(z);
	SNODE<T>* prev = headptr;//temp ptr
	SNODE<T>* current = headptr;// temp ptr
	int position = 0;

	if (headptr->getnext() != NULL)
	{
		while (current->getnext() != NULL && position < input)
		{
			prev = current;
			current = current->getnext();
			position++;
		}
		if (position == 0)
		{
			current->setnext(newSNODE);
			newSNODE->setnext(NULL);
			length++;
		}
		else if ((current->getnext() == NULL) && (position + 1 == input))
		{
			current->setnext(newSNODE);
			newSNODE->setnext(NULL);
			length++;
		}
		else if (position < input)
		{
			cout << "Out of bounds, cannot add." << endl;
		}
		else
		{
			prev->setnext(newSNODE);
			newSNODE->setnext(current);
			length++;
		}
	}
	else
	{
		headptr->setnext(newSNODE);
		newSNODE->setnext(NULL);
		length++;
	}
}

/*deleteSNODE()
set input to par value
set prev to headptr
set current to headptr
set position to 0

if headSNODE points to !Null
while current SNODE.next !=Null and position < input
prev=current
set current point to next SNODE
increment psition
end loop
if position == 0
set previous SNODE point to SNODE after current
decrement list length
delete current SNODE
else if current SNODE points to NULL and position == input
set previous SNODE point to NULL
decrement list length
delete current SNODE
else if position < input
prompt user operation failed
else
set previous SNODE point to SNODE after current
decrement list length
delete current SNODE
end if
else
prompt user list is empty
end if

end method

*/
template <class T>
void linkedlist<T>::deletenode(int input)
{
	SNODE<T> *prev = headptr;
	SNODE<T> *current = headptr;//temp SNODEs

	int position = 0;

	if (headptr->getnext() != NULL)
	{
		while (current->getnext() != NULL && position < input)//move current and prev pointers to position
		{
			prev = current;
			current = current->getnext();
			position++;
		}
		if (position == 0)
		{
			prev->setnext(current->getnext());
			length--;
			delete current;
		}
		else if ((current->getnext() == NULL) && (position == input))
		{
			prev->setnext(NULL);
			length--;
			delete current;
		}
		else if (position < input)
		{
			cout << "Out of bounds, can not delete." << endl;
		}
		else
		{
			prev->setnext(current->getnext());
			length--;
			delete current;
		}
	}
	else
	{
		cout << "List is empty, nothing to delete." << endl;
	}
}

/*locate()
set z to par value
set temp to headptr
set position to 0
while SNODE data != z and position < length
set temp point to next SNODE
increment position
end loop
if temp->data ==z
return position
else
return -1
end if
return -1
end method
*/
template <class T>
int linkedlist<T>::locate(T z)
{
	SNODE<T>* temp = headptr;

	int position = 0;
	while ((temp->getdata() != z) && (position<length))
	{
		temp = temp->getnext();
		position++;
	}
	if (temp->getdata() == z)
	{
		return position;
	}
	else
	{
		return -1;
	}
	return -1;//returns -1 if not found
}


template <class T>
int linkedlist<T>::listlength()
{
	return length;
}
/*deletelist()
set current point to first dataSNODE or null if no dataSNODE
while current != NULL
set headSNODE point to succeeding dataSNODE
set dataSNODE point to NULL
delete current dataSNODE
set current point to the next dataSNODE
end loop
end method

*/
template <class T>
void linkedlist<T>::deletelist()
{
	SNODE<T>* current = headptr->getnext();

	while (current != NULL)
	{
		headptr->setnext(current->getnext());
		current->setnext(NULL);
		free(current);
		current = headptr->getnext();
	}
}


#endif