#include"HP.h"
#include<iostream>
Hp::Hp(int amount)
	:m_Data(amount) {

}

bool Hp::Use()
{
	if (m_Data > 0) {
		m_Data--;
		std::cout << "Use HP : " << m_Data << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void Hp::Take()
{
	//0이하 예외처리 필요
	//temp
	std::cout << m_Data << " -> ";
	m_Data += 10;
	if (m_Data > 100)
		set(100);
	std::cout << m_Data << "Take HP" << std::endl;
}
void Hp::Lose(int _val)
{
	m_Data -= _val;
	if (m_Data <= 0) {
		m_Data = 0;
	}
}
int Hp::get() const
{
	return m_Data;
}

void Hp::set(int Data)
{
	m_Data = Data;
}
