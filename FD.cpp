#include"FD.h"
#include<iostream>
Food::Food(int amount)
	:m_Data(amount) {

}

bool Food::Use()
{
	if (m_Data > 0) {
		m_Data--;
		std::cout << "Use FD : " << m_Data << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void Food::Take()
{
	//temp
	std::cout << m_Data << " -> ";
	m_Data += 20;
	if (m_Data > 100)
		set(100);
	std::cout << m_Data << "Take FD" << std::endl;
}

void Food::Lose(int _val)
{
	m_Data -= _val;
	if (m_Data <= 0) {
		m_Data = 0;
	}
}

int Food::get() const
{
	return m_Data;
}

void Food::set(int Data)
{
	m_Data = Data;
}
