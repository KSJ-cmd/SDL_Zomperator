#include<iostream>
#include"MD.h"

Medicine::Medicine(int amount)
	:m_Data(amount) {

}

bool Medicine::Use()
{
	if (m_Data > 0) {
		m_Data--;
		std::cout << "Use MD : " << m_Data << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void Medicine::Take()
{
	//temp
	std::cout << m_Data << " -> ";
	m_Data += 20;
	if (m_Data > 100)
		set(100);
	std::cout << m_Data << "Take MD" << std::endl;
}

void Medicine::Lose(int _val)
{
	m_Data -= _val;
	if (m_Data <= 0) {
		m_Data = 0;
	}
}

int Medicine::get() const
{
	return m_Data;
}

void Medicine::set(int Data)
{
	m_Data = Data;
}
