#include "assert.h"
#include <iostream>
#include "ConnectFour.h"
int main()
{
	ConnectFour game(7, 6);
	bool playGame = true;
	while(playGame == true)
	{
		playGame = game.Update();
	}
}