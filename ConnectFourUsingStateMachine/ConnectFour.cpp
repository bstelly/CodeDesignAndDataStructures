#include "ConnectFour.h"
#include "iostream"

ConnectFour::ConnectFour()
{
}

ConnectFour::ConnectFour(int numCols, int colHeights)
{
	m_Columns = new Column[numCols];
	m_NumCols = numCols;
	m_ColHeights = colHeights;
	for (int i = 0; i <= m_NumCols; i++)
	{
		m_Columns[i] = Column(m_ColHeights);
	}
	m_ActiveToken = 'O';
}

bool ConnectFour::PlacePiece(int col)
{
	return m_Columns[col].PlaceToken(m_ActiveToken);
}

bool ConnectFour::Update()
{
	int player = 1;
	int input;
	while (!CheckVictory())
	{
		DisplayBoard();
		player = (player % 2) ? 1 : 2;
		m_ActiveToken = (player == 1) ? 'O' : 'X';
		std::cout << "Player " << m_ActiveToken << " it is your turn. Select a column\n";
		std::cin >> input;
		while (input > m_NumCols - 1)
		{
			std::cout << "The number you inputted does not correspond to a column\n";
			std::cout << "Select a column\n";
			std::cin >> input;
		}
		PlacePiece(input);
		player++;
		system("cls");

	}
	std::cout << "Would you like to play again?\n";
	std::cout << "( 1 ) Yes	( 2 ) No\n";
	int playAgain;
	std::cin >> playAgain;
	if (playAgain == 1)
	{
		return true;
	}
	return false;
}

bool ConnectFour::CheckVictory()
{
	for (int i = 0; i < m_NumCols; i++)
	{
		for (int j = 0; j < m_ColHeights; j++)
		{
			//Check Horizontal Win
			if ((m_Columns[i].m_Cells[j] == m_Columns[i + 1].m_Cells[j] &&
				m_Columns[i + 1].m_Cells[j] == m_Columns[i + 2].m_Cells[j] &&
				m_Columns[i + 2].m_Cells[j] == m_Columns[i + 3].m_Cells[j]) ||
				//Check Vertical Win
				(m_Columns[i].m_Cells[j] == m_Columns[i].m_Cells[j + 1] &&
					m_Columns[i].m_Cells[j + 1] == m_Columns[i].m_Cells[j + 2] &&
					m_Columns[i].m_Cells[j + 2] == m_Columns[i].m_Cells[j + 3]) ||
				//Check Diagonal Wins
					(m_Columns[i].m_Cells[j] == m_Columns[i + 1].m_Cells[j + 1] &&
						m_Columns[i + 1].m_Cells[j + 1] == m_Columns[i + 2].m_Cells[j + 2] &&
						m_Columns[i + 2].m_Cells[j + 2] == m_Columns[i + 3].m_Cells[j + 3]))
			{
				DisplayBoard();
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	//Continue checking for diagonal wins
	for (int i = 3; i < m_NumCols; i++)
	{
		for (int j = 0; j < m_ColHeights; j++)
		{
			if (m_Columns[i].m_Cells[j] == m_Columns[i - 1].m_Cells[j - 1] &&
				m_Columns[i - 1].m_Cells[j - 1] == m_Columns[i - 2].m_Cells[j - 2] &&
				m_Columns[i - 2].m_Cells[j - 2] == m_Columns[i - 3].m_Cells[j - 3])
			{
				DisplayBoard();
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	for (int i = 0; i < m_NumCols; i++)
	{
		for (int j = 3; j < m_ColHeights; j++)
		{
			if (m_Columns[i].m_Cells[j] == m_Columns[i + 1].m_Cells[j - 1] &&
				m_Columns[i + 1].m_Cells[j - 1] == m_Columns[i + 2].m_Cells[j - 2] &&
				m_Columns[i + 2].m_Cells[j - 2] == m_Columns[i + 3].m_Cells[j - 3])
			{
				DisplayBoard();
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
				return true;
			}
		}
	}
	return false;
}

void ConnectFour::DisplayBoard()
{
	for (int i = m_ColHeights - 1; i >= 0; i--)
	{
		for (int j = 0; j < m_NumCols; j++)
		{
			std::cout << "(" << m_Columns[j].m_Cells[i].m_Token << ")";
		}
		std::cout << std::endl;
	}
	int counter = 0;
	while (counter <= m_NumCols - 1)
	{
		std::cout << " " << counter << " ";
		counter++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
}


void ConnectFour::UpdateInit()
{
	for (int i = 0; i < m_NumCols; i++)
	{
		for (int j = 0; j < m_ColHeights; j++)
		{
			m_Columns[i].m_Cells[j].m_Token = ' ';
		}
	}
	for (int i = 0; i < m_NumCols; i++)
	{
		m_Columns[i].m_LastOccupied = -1;
	}
	system("cls");
}

void ConnectFour::UpdateCheckVictory()
{
	for (int i = 0; i < m_NumCols; i++)
	{
		for (int j = 0; j < m_ColHeights; j++)
		{
			//Check Horizontal Win
			if ((m_Columns[i].m_Cells[j] == m_Columns[i + 1].m_Cells[j] &&
				m_Columns[i + 1].m_Cells[j] == m_Columns[i + 2].m_Cells[j] &&
				m_Columns[i + 2].m_Cells[j] == m_Columns[i + 3].m_Cells[j]) ||
				//Check Vertical Win
				(m_Columns[i].m_Cells[j] == m_Columns[i].m_Cells[j + 1] &&
					m_Columns[i].m_Cells[j + 1] == m_Columns[i].m_Cells[j + 2] &&
					m_Columns[i].m_Cells[j + 2] == m_Columns[i].m_Cells[j + 3]) ||
				//Check Diagonal Wins
					(m_Columns[i].m_Cells[j] == m_Columns[i + 1].m_Cells[j + 1] &&
						m_Columns[i + 1].m_Cells[j + 1] == m_Columns[i + 2].m_Cells[j + 2] &&
						m_Columns[i + 2].m_Cells[j + 2] == m_Columns[i + 3].m_Cells[j + 3]))
			{
				DisplayBoard();
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
			}
		}
	}
	//Continue checking for diagonal wins
	for (int i = 3; i < m_NumCols; i++)
	{
		for (int j = 0; j < m_ColHeights; j++)
		{
			if (m_Columns[i].m_Cells[j] == m_Columns[i - 1].m_Cells[j - 1] &&
				m_Columns[i - 1].m_Cells[j - 1] == m_Columns[i - 2].m_Cells[j - 2] &&
				m_Columns[i - 2].m_Cells[j - 2] == m_Columns[i - 3].m_Cells[j - 3])
			{
				DisplayBoard();
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
			}
		}
	}
	for (int i = 0; i < m_NumCols; i++)
	{
		for (int j = 3; j < m_ColHeights; j++)
		{
			if (m_Columns[i].m_Cells[j] == m_Columns[i + 1].m_Cells[j - 1] &&
				m_Columns[i + 1].m_Cells[j - 1] == m_Columns[i + 2].m_Cells[j - 2] &&
				m_Columns[i + 2].m_Cells[j - 2] == m_Columns[i + 3].m_Cells[j - 3])
			{
				DisplayBoard();
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				std::cout << std::endl;
				system("pause");
				system("cls");
			}
		}
	}
}

void ConnectFour::UpdateGameOver()
{

}

void ConnectFour::UpdatePlayerOne()
{

}

void ConnectFour::UpdatePlayerTwo()
{

}

