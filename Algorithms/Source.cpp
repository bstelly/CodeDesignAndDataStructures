#include <assert.h>


int SearchLargest(int * collection, int numItems)
{
	if (numItems <= 0)
	{
		return NULL;
	}
	int biggestNum = collection[0];
	for(int i = 0; i < numItems; i++)
	{
		if(collection[i] > biggestNum)
		{
			biggestNum = collection[i];
		}
	}
	return biggestNum;
}

int main()
{
	int numbers[5] = { 1. -3, 4, 100, -100 };
	int result = SearchLargest(numbers, 5);
	assert(result == 100);
}