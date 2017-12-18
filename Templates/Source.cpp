#include <iostream>

//Takes in two arguments and adds them together
template<typename T>
T Add(T rhs, T lhs)
{
	return lhs + rhs;
}

//Takes in two arguments and subtracts them together
template<typename T>
T Subtract(T lhs, T rhs)
{
	return lhs - rhs;
}

template<typename Type>
class Node
{
public:
	Type m_Data;
	Node()
	{
		m_Data = 0;
	}
	Node(Type data)
	{
		m_Data = data;
	}
	bool operator== (Node<Type> rhs)
	{
		return m_Data == rhs.m_Data;
	}
	bool operator !=(Node<Type> rhs)
	{
		return m_Data != rhs.m_Data;
	}
};

int main()
{
	int a = 29;
	int b = 32;
	int test = Add<int>(a, b);
	int testTwo = Subtract<int>(b, a);
}