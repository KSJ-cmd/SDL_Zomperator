#include"WP.h"
#include<iostream>
Weapon::Weapon(int amount)
	:m_Data(amount) {

}

bool Weapon::Use()
{
	if (m_Data > 0) {
		m_Data--;
		std::cout << "Use WP : " << m_Data << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void Weapon::Take()
{
	//temp
	std::cout << m_Data << " -> ";
	m_Data += 20;
	if (m_Data > 100)
		set(100);
	std::cout << m_Data << "Take WP" << std::endl;
}

void Weapon::Lose(int _val)
{
	m_Data -= _val;
	if (m_Data <= 0) {
		m_Data = 0;
	}
}

int Weapon::get() const
{
	return m_Data;
}

void Weapon::set(int Data)
{
	m_Data = Data;
}
