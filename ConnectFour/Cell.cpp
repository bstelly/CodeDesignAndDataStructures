#include "Cell.h"

Cell::Cell()
{
	m_Token = ' ';
}

Cell::Cell(char token)
{
	m_Token = token;
}

bool Cell::operator==(Cell& other)
{
	if (m_Token == ' ' || other.m_Token == ' ')
	{
		return false;
	}
	return m_Token == other.m_Token;
}
