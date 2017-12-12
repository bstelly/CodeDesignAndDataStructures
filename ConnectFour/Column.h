#pragma once
#include "Cell.h"
class Column
{
public:
	int m_Height;
	Cell* m_Cells;
	int m_LastOccupied = -1;
	Column();
	Column(int height);
	bool PlaceToken(char token);
	bool IsFull();
};