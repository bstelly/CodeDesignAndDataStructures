#pragma once
#include "Column.h"

class ConnectFour
{
public:
	enum eState { INIT, PLAYERONE, CHECKVICTORY, PLAYERTWO, GAMEOVER };
	eState m_State = eState::INIT;
	Column* m_Columns;
	char m_ActiveToken;
	int m_NumCols;
	int m_ColHeights;
	ConnectFour(int numCols, int colHeights);
	ConnectFour();
	bool Update();
	bool PlacePiece(int col);
	bool CheckVictory();
	void DisplayBoard();
	void UpdateInit();
	void UpdatePlayerOne();
	void UpdateCheckVictory();
	void UpdatePlayerTwo();
	bool UpdateGameOver();
};