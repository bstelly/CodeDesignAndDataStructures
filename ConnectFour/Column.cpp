#include "Column.h"
#include <iostream>

Column::Column()
{
}

Column::Column(int height)
{
	m_Height = height;
	m_Cells = new Cell[m_Height];
}

bool Column::PlaceToken(char token)
{
	if (!IsFull())
	{
		m_LastOccupied = m_LastOccupied + 1;

		m_Cells[m_LastOccupied] = token;
		return true;
	}
}

bool Column::IsFull()
{
	if(m_LastOccupied == m_Height - 1)
	{
		return true;
	}
	return false;
}

