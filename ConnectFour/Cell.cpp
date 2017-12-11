#include "Cell.h"

Cell::Cell()
{
	m_Token = '\n';
}

Cell::Cell(char token)
{
	m_Token = token;
}

bool Cell::operator==(Cell& other)
{
	if (m_Token == '\0' || other.m_Token == '\0')
	{
		return false;
	}
	return m_Token == other.m_Token;
}
