#include<iostream>
#include"ResourceData.h"
ResourceData::ResourceData(Weapon* weapon, Medicine* medicine, Food* food)
	:m_Weapon(weapon),m_Food(food),m_Medicine(medicine)
{
}

ResourceData::~ResourceData()
{
	delete m_Weapon;
	delete m_Medicine;
	delete m_Food;
}

ResourceData& ResourceData::operator=(const ResourceData& rsh)
{
	m_Weapon = new Weapon(*rsh.m_Weapon);
	m_Medicine = new Medicine(*rsh.m_Medicine);
	m_Food = new Food(*rsh.m_Food);
	return *this;
}

void ResourceData::takeWP(int _amount)
{
	std::cout << "take WP amount" << _amount << std::endl;
	int sum = m_Weapon->get();
	sum += _amount;
	m_Weapon->set(sum);
}

void ResourceData::takeFD(int _amount)
{
	std::cout << "take FD amount" << _amount << std::endl;
	int sum = m_Food->get();
	sum += _amount;
	m_Food->set(sum);
}

void ResourceData::takeMD(int _amount)
{
	std::cout << "take MD amount" << _amount << std::endl;
	int sum = m_Medicine->get();
	sum += _amount;
	m_Medicine->set(sum);
}

Weapon* ResourceData::getWP() const
{
	return m_Weapon;
}

Food* ResourceData::getFD() const
{
	return m_Food;
}

Medicine* ResourceData::getMD() const
{
	return m_Medicine;
}

