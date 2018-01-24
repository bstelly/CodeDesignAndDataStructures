#pragma once
#include "NodeType.h"
#include <cstddef>

template<class Type>
class LinkedListIterator
{
private:
	//Definition: Pointer to point to the current node in the linked list
	NodeType<Type> *current;

public:
	//Default Constructor
	//Description: Sets Current equal to NULL
	LinkedListIterator()
	{
		*current = NULL;
	}

	//Constructor with a parameter
	//Postcondition: Assigns current the value of pointer
	LinkedListIterator(NodeType<Type> *ptr)
	{
		current = ptr;
	}

	//Function to overload the derefrence operator
	//Description: Return the info contained in the node
	Type operator*()
	{
		return current->info;
	}

	//Description: Overload the pre-increment operator
	//Postcondition the iterator is advanced to the next node
	LinkedListIterator<Type>operator++()
	{
		current = current->link;
		return *this;
	}

	//Description: Overload the equality operator
	//Postcondition: Returns true if this iterator is equal to the iterator specified by
	//right otherwise it returns false
	bool operator==(const LinkedListIterator<Type>& right) const
	{
		return *current == right->current;
	}

	//Description: Overload the not equal to operator
	//Postcondition: Return true if this iterator is not equal to the iterator specified
	//by right otherwise it returns false
	bool operator!=(const LinkedListIterator<Type>& right) const
	{
		return *current != right->current;
	}
};