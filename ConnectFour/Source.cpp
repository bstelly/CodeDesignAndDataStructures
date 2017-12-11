#include "assert.h"
#include <iostream>
#include "ConnectFour.h"
int main()
{
	Cell testOne('x');
	Cell testTwo('o');
	//assert(testOne == testTwo);
	ConnectFour game(7, 6);
	game.Update();
	system("pause");
}