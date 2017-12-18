#pragma once
#include "LinkedListIterator.h"
#include <ostream>

template<class Type>
class LinkedListType
{
protected:
	int count;				//variable to store the number of elements in the list
	NodeType<Type> *first;	//Pointer to the first node of the list
	NodeType<Type> *last;	//pointer to the last node of the list

public:
	//Overload the assignment operator
	const LinkedListType<Type>& operator=(const LinkedListType<Type>&)
	{
		
	}

	//Initialize the list to an empty state
	//Postcondition: first = NULL, count = 0
	void InitializeList()
	{
		
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
		NodeType<Type> *temp = first;
		int iter = 0;
		while (temp != NULL)
		{
			iter++;
			temp = temp->link;
		}
		return iter;
	}

	//Function to delete all the nodes from the list
	//Postcondition: first = NULL, last = NULL, count = 0
	void DestroyList()
	{
		NodeType<Type> *temp = first;
		while (temp != NULL)
		{
			delete temp;
			temp = temp->link;
		}
	}

	//Function to return the first element of the list
	//Precondition: the list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise, the first
	//element of the list is required
	Type Front()
	{
		
	}

	//Function to return the last element of the list
	//Precondition: the list must exist and must not be empty
	//Postcondition: If the list is empty, the program terminates; otherwise, the last
	//element of the list is returned
	Type Back()
	{
		
	}

	//Function to determine whether searchItem is in the list
	//Postcondition: Returns true if searchItem is in the list,otherwise the value false
	//is returned
	bool Search(const Type&) const
	{
		
	}

	//Function to insert newItem at the beginning of the list
	//Postcondition: First points to the new list, newItem is inserted at the beginning
	//of the list, last points to the last node in the list and count is incremented
	//by one
	void InsertFirst(const Type&)
	{
		
	}

	//Function to insert newItem at the end of the list
	//Postcondition: first points to the new list, newItem is inserted at the end of the
	//list, last points to the last node in the list and count is incremented by one
	void InsertLast(const Type&)
	{
		
	}

	//Function to delete deleteItem from the list
	//Postcondition: If found, the node containing deleteItem is deleted from the list.
	//First points to the first node, list points to the last node of the updated list,
	//and counts is decremented by one
	void DeleteNode(const type&)
	{
		
	}

	//Function to return an iterator at the beginning of the linked list
	//Postcondition: Returns an iterator such that current is set to first
	LinkedListIterator<Type> Begin()
	{
		
	}

	//Function to return an iterator at the end of the linked list
	//Postcondition: Returns an iterator such that current is set to NULL
	LinkedListIterator<Type> End()
	{
		
	}

	//Default constructor
	//Initializes the list to an empty state
	//Postcondition: first = null, last = null, count = 0
	LinkedListType()
	{
		
	}

	//Copy constructor
	LinkedListType(const LinkedListType<Type>&)
	{
		
	}

	//Destructor
	//Deletes all the nodes from the list
	//Postcondition: the list objects is destroyed
	~LinkedListType()
	{
		
	}

private:
	//Function to make a copy of otherList
	//Postcondition: a copy of otherList is created and assigned to this list
	void CopyList(const LinkedListType<Type>&)
	{
		
	}
};
