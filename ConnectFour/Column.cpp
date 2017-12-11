#include "Column.h"

Column::Column()
{
}

Column::Column(int height)
{
	m_Height = height;
	m_Cells = new Cell[6];
	for(int i = 0; i < 6; i ++)
	{
		m_Cells[i].m_Token = '\0';
	}
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
	if(m_LastOccupied == m_Height)
	{
		return true;
	}
}

