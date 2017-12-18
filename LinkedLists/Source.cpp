#include "NodeType.h"
#include "LinkedListIterator.h"

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
	LinkedListIterator<int> iter = LinkedListIterator<int>(&a);
}