#include <iostream>

class TrafficLight
{
	enum eState {INIT, REDLIGHT, YELLOWLIGHT, GREENLIGHT, OFF };
	eState m_State = eState::INIT;
	int m_Ticks;
	TrafficLight()
	{
		m_State = eState::REDLIGHT;
	}
	void Update()
	{
		while (m_State != eState::OFF)
		{
			std::cout << "How many ticks have passed? \n";
			std::cin >> m_Ticks;
			switch(m_Ticks)
			{
			case 0:
				if(m_State == eState::YELLOWLIGHT || m_State == eState::INIT)
				m_State = eState::REDLIGHT;
				break;
			case 1:
				if(m_State == eState::GREENLIGHT)
				m_State = eState::YELLOWLIGHT;
				break;
			case 2:
				if(m_State == REDLIGHT)
				m_State = eState::GREENLIGHT;
				break;
			default:
				if(m_State != eState::INIT)
				m_State = eState::OFF;
				break;
			}
		}
	}
};

int main()
{

}