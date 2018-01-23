#pragma once
#include "LinkedListIterator.h"
#include <iostream>
#include <assert.h>

template<class Type>
class LinkedListType
{
protected:
	int count;				//variable to store the number of elements in the list
	NodeType<Type> *first;	//Pointer to the first node of the list
	NodeType<Type> *last;	//pointer to the last node of the list

public:
	//Overload the assignment operator
	const LinkedListType<Type>& operator=(const LinkedListType<Type> &rhs)
	{
		return CopyList(rhs);
	}

	//Initialize the list to an empty state
	//Postcondition: first = NULL, count = 0
	void InitializeList()
	{
		DestroyList();
	}

	//Funtion to determine whether the list is empty
	//PostCondition: Returns true if the list is empty otherwise it returns false
	bool IsEmptyList()
	{
		return first == NULL;
	}

	//Function to return the of nodes in the list
	//PostCondition: node
	void const Print()
	{
		NodeType<Type> *temp = first;
		while (temp != NULL)
		{
			std::cout << temp->info << std::endl;
			temp = temp->link;
		}
	}

	//Function to return the of nodes in the list
	//Postcondition: The value of count is returned
	int Length()
	{
		return count;
	}

	//Function to delete all the nodes from the list
	//Postcondition: first = NULL, last = NULL, count = 0
	void DestroyList()
	{
		NodeType<Type> *temp;
		while (first != NULL)
		{
			temp = first;
			first = first->link;
			delete temp;
		}
		last = NULL;
		count = 0;
	}

	//Function to return the first element of the list
	//Precondition: the list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise, the first
	//element of the list is required
	Type Front()
	{
			assert(first != NULL);
			return first;
	}

	//Function to return the last element of the list
	//Precondition: the list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise, the last
	//element of the list is returned
	Type Back()
	{
			assert(last != NULL);
			return last;
	}

	//Function to determine whether searchItem is in the list
	//Postcondition: Returns true if searchItem is in the list,otherwise the value false
	//is returned
	bool Search(const Type &rhs) const
	{
		NodeType<Type> *temp = first;
		int counter = 0;
		while(counter <= count)
		{
			if(temp->info == rhs)
			{
				return true;
			}
			counter++;
			temp = temp->link;
		}
		return false;
	}

	//Function to insert newItem at the beginning of the list
	//Postcondition: First points to the new list, newItem is inserted at the beginning
	//of the list, last points to the last node in the list and count is incremented
	//by one
	void InsertFirst(const Type &rhs)
	{
		NodeType<Type>* newItem = new NodeType<Type>;
		newItem->info = rhs;
		newItem->link = first;
		first = newItem;
		count += 1;
	}

	//Function to insert newItem at the end of the list
	//Postcondition: first points to the new list, newItem is inserted at the end of the
	//list, last points to the last node in the list and count is incremented by one
	void InsertLast(const Type &rhs)
	{
		NodeType<Type>* newItem = new NodeType<Type>;
		newItem->info = rhs;
		newItem->link = NULL;
		if(first == NULL)
		{
			first = newItem;
			last = newItem;
			count += 1;
		}
		else
		{
			NodeType<Type> *temp = first;
			while (temp->link)
			{
				temp = temp->link;
			}
			temp->link = newItem;
			count += 1;
			last = newItem;
		}
	}

	//Function to delete deleteItem from the list
	//Postcondition: If found, the node containing deleteItem is deleted from the list.
	//First points to the first node, list points to the last node of the updated list,
	//and counts is decremented by one
	void DeleteNode(const Type &rhs)
	{
		NodeType<Type> *current = new NodeType<Type>;
		NodeType<Type> *previous = new NodeType<Type>;
		if(first->info == rhs)
		{
			current = first;
			first = first->link;
			delete current;
			count -= 1;
		}
		else
		{
			current = first->link;
			previous = first;
			while (current != NULL)
			{
				if (current->info == rhs)
				{
					previous->link = current->link;
					delete current;
					count -= 1;
					break;
				}
				else
				{
					previous = previous->link;
					current = current->link;
				}
			}
		}
	}

	//Function to return an iterator at the beginning of the linked list
	//Postcondition: Returns an iterator such that current is set to first
	LinkedListIterator<Type> Begin()
	{
		LinkedListIterator<Type>* temp;
		temp->current = first;
		return temp;
	}

	//Function to return an iterator at the end of the linked list
	//Postcondition: Returns an iterator such that current is set to NULL
	LinkedListIterator<Type> End()
	{
		LinkedListIterator<Type>* temp;
		temp->current = last;
		return temp;
	}

	//Default constructor
	//Initializes the list to an empty state
	//Postcondition: first = null, last = null, count = 0
	LinkedListType()
	{
		first = NULL;
		last = NULL;
		count = 0;
	}

	//Copy constructor
	LinkedListType(const LinkedListType<Type> &rhs)
	{
		CopyList(rhs);
	}

	//Destructor
	//Deletes all the nodes from the list
	//Postcondition: the list objects are destroyed
	~LinkedListType()
	{
		DestroyList();
	}

private:
	//Function to make a copy of otherList
	//Postcondition: a copy of otherList is created and assigned to this list
	void CopyList(const LinkedListType<Type> &rhs)
	{
		DestroyList();
		NodeType<Type>* newNode = new NodeType<Type>;
		newNode->info = rhs.first->info;
		InsertFirst(newNode->info);
		newNode = rhs.first->link;
		while (first->info != NULL)
		{
			InsertFirst(newNode->info);
			newNode = newNode->link;
		}
	}
};