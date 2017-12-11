#pragma once
#include "Column.h"

class ConnectFour
{
public:
	Column* m_Columns;
	char m_ActiveToken;
	int m_NumCols;
	int m_ColHeights;
	ConnectFour(int numCols, int colHeights);
	ConnectFour();
	bool Update();
	bool PlacePiece(int col);
	bool CheckVictory();
};