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
}

bool ConnectFour::PlacePiece(int col)
{
	return m_Columns[col].PlaceToken(m_ActiveToken);
}

bool ConnectFour::Update()
{
	//while(!CheckVictory())
	//{
	
	/*}*/
	return true;
}

bool ConnectFour::CheckVictory()
{
	for (int i = 0; i < m_NumCols; i++)
	{
		for (int j = 0; j < m_ColHeights; j++)
		{
			//Check Horizontal Win
			if ((m_Columns[i].m_Cells[j].m_Token == m_Columns[i + 1].m_Cells[j].m_Token &&
				m_Columns[i + 1].m_Cells[j].m_Token == m_Columns[i + 2].m_Cells[j].m_Token &&
				m_Columns[i + 2].m_Cells[j].m_Token == m_Columns[i + 3].m_Cells[j].m_Token) ||
				//Check Vertical Win
				(m_Columns[i].m_Cells[j].m_Token == m_Columns[i].m_Cells[j + 1].m_Token &&
				m_Columns[i].m_Cells[j + 1].m_Token == m_Columns[i].m_Cells[j + 2].m_Token &&
				m_Columns[i].m_Cells[j + 2].m_Token == m_Columns[i].m_Cells[j + 3].m_Token) ||
					//Check Diagonal Win
				(m_Columns[i].m_Cells[j].m_Token == m_Columns[i + 1].m_Cells[j + 1].m_Token &&
				m_Columns[i + 1].m_Cells[j + 1].m_Token == m_Columns[i + 2].m_Cells[j + 2].m_Token &&
				m_Columns[i + 2].m_Cells[j + 2].m_Token == m_Columns[i + 3].m_Cells[j + 3].m_Token))
			
			{
				std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
				return true;
			}
		}
	}
	
//	//Check Vertical Win
//	for(int i = 0; i < m_NumCols; i++)
//	{
//		for (int j = 0; j < m_ColHeights; j++)
//		{
//			if(m_Columns[i].m_Cells[j].m_Token == m_Columns[i].m_Cells[j + 1].m_Token &&
//				m_Columns[i].m_Cells[j + 1].m_Token == m_Columns[i].m_Cells[j + 2].m_Token &&
//				m_Columns[i].m_Cells[j + 2].m_Token == m_Columns[i].m_Cells[j + 3].m_Token)
//			{
//				
//			}
//		}
//	}
//

////Check Diagonal Win
	//for (int i = 0; i < m_NumCols; i++)
	//{
	//	for (int j = 0; j < m_ColHeights; j++)
	//	{
	//		if (m_Columns[i].m_Cells[j].m_Token == m_Columns[i + 1].m_Cells[j + 1].m_Token &&
	//			m_Columns[i + 1].m_Cells[j + 1].m_Token == m_Columns[i + 2].m_Cells[j + 2].m_Token &&
	//			m_Columns[i + 2].m_Cells[j + 2].m_Token == m_Columns[i + 3].m_Cells[j + 3].m_Token)
	//		{
	//			std::cout << "Player " << m_ActiveToken << " Wins" << std::endl;
	//		}
	//	}
	//}




}


