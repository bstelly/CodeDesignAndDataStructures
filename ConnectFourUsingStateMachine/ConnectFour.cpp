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
	m_State = eState::INIT;
}

bool ConnectFour::PlacePiece(int col)
{
	return m_Columns[col].PlaceToken(m_ActiveToken);
}

bool ConnectFour::Update()
{
	bool play = true;
	switch (m_State)
	{
	case eState::INIT:
		UpdateInit();
		break;
	case eState::PLAYERONE:
		UpdatePlayerOne();
		break;
	case eState::CHECKVICTORY:
		UpdateCheckVictory();
		break;
	case eState::PLAYERTWO:
		UpdatePlayerTwo();
		break;
	case eState::GAMEOVER:
		play = UpdateGameOver();
		break;

	}
	if(play == false)
	{
		return false;
	}
	return true;
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
	m_State = eState::PLAYERONE;
}

void ConnectFour::UpdateCheckVictory()
{
	system("cls");
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
				m_State = eState::GAMEOVER;
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
				m_State = eState::GAMEOVER;
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
				m_State = eState::GAMEOVER;
			}
		}
	}
	if(m_ActiveToken == 'X' && m_State != eState::GAMEOVER)
	{
		m_State = eState::PLAYERONE;
	}
	else if(m_ActiveToken == 'O' && m_State != eState::GAMEOVER)
	{
		m_State = eState::PLAYERTWO;
	}
	else
	{
		m_State = eState::GAMEOVER;
	}
}

bool ConnectFour::UpdateGameOver()
{
	system("cls");
	std::cout << "Would you like to play again?\n";
	std::cout << "( 1 ) Yes	( 2 ) No\n";
	int playAgain;
	std::cin >> playAgain;
	if(playAgain == 1)
	{
		m_State = eState::INIT;
		return true;
	}
	return false;
}

void ConnectFour::UpdatePlayerOne()
{
	system("cls");
	DisplayBoard();
	m_ActiveToken = 'O';
	int input;
	std::cout << "Player " << m_ActiveToken << " it is your turn. Select a column\n";
	std::cin >> input;
	while (input > m_NumCols - 1)
	{
		std::cout << "The number you inputted does not correspond to a column\n";
		std::cout << "Select a column\n";
		std::cin >> input;
	}
	PlacePiece(input);
	m_State = eState::CHECKVICTORY;

}

void ConnectFour::UpdatePlayerTwo()
{
	system("cls");
	DisplayBoard();
	m_ActiveToken = 'X';
	int input;
	std::cout << "Player " << m_ActiveToken << " it is your turn. Select a column\n";
	std::cin >> input;
	while (input > m_NumCols - 1)
	{
		std::cout << "The number you inputted does not correspond to a column\n";
		std::cout << "Select a column\n";
		std::cin >> input;
	}
	PlacePiece(input);
	m_State = eState::CHECKVICTORY;

}