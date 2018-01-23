#include "NodeType.h"
#include "LinkedListIterator.h"
#include "LinkedListType.h"
#include <iostream>
#include "assert.h"

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
	list->InsertFirst(70);
	list->InsertFirst(80);
	list->InsertLast(60);
	LinkedListType<int>* otherList = list;
	LinkedListType<int> *newList(list);
	newList->Print();
	list->DeleteNode(60);
	assert(list->Search(10) == true);
}