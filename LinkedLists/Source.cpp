#include "NodeType.h"
#include "LinkedListIterator.h"
#include "LinkedListType.h"
#include <iostream>

int main()
{
	NodeType<int> a = { 50 };
	NodeType<int> b = { 30 };
	NodeType<int> c = { 10 };
	NodeType<int> d = { 1 };
	a.link = &b;
	b.link = &c;
	c.link = &d;
	d.link = NULL;
	LinkedListIterator<int> iter = LinkedListIterator<int>(&c);
	LinkedListType<int>* list = new LinkedListType<int>;
	list->IsEmptyList();
	list->InsertFirst(10);
	list->InsertFirst(50);
	list->InsertLast(60);
	LinkedListType<int>* otherList = new LinkedListType<int>;
	LinkedListType<int> *newList(list);
}