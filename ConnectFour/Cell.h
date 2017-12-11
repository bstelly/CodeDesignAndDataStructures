#pragma once

class Cell
{
public:
	char m_Token;
	Cell();
	Cell(char token);
	bool operator == (Cell & other);
};