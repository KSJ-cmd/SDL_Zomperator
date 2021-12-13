#include "InfoData.h"
#include"NationHandler.h"
#include"Nation.h"
InfoData::InfoData()
	:m_Nations(NationHandler::getNations())
	,m_Hps(m_Nations.size()), m_Wps(m_Nations.size()), m_Mds(m_Nations.size()), m_Fds(m_Nations.size())
{
	updateData();
}

InfoData::~InfoData()
{
	std::cout << "InfoData delete " << std::endl;
}

InfoData::InfoData(const InfoData& src)
	:m_Nations(src.m_Nations)
{
}

InfoData& InfoData::operator=(const InfoData& rsh)
{
	return *this;
}

const std::vector<Nation*>& InfoData::getNations() const
{
	return m_Nations;
}

const std::vector<int>& InfoData::getHps() const
{
	return m_Hps;
}

const std::vector<int>& InfoData::getWps() const
{
	return m_Wps;
}

const std::vector<int>& InfoData::getMds() const
{
	return m_Mds;
}

const std::vector<int>& InfoData::getFds() const
{
	return m_Fds;
}

std::vector<Nation*>& InfoData::getNations() 
{
	return m_Nations;
}

 std::vector<int>& InfoData::getHps() 
{
	return m_Hps;
}

 std::vector<int>& InfoData::getWps() 
{
	return m_Wps;
}

 std::vector<int>& InfoData::getMds() 
{
	return m_Mds;
}

 std::vector<int>& InfoData::getFds() 
{
	return m_Fds;
}


void InfoData::updateData()
{
	int num = 0;

	for (std::vector<Nation*>::iterator iter = m_Nations.begin(); iter != m_Nations.end(); iter++) {
		m_Hps[num] = (*iter)->getHp()->get();
		m_Wps[num] = (*iter)->getWp()->get();
		m_Mds[num] = (*iter)->getMd()->get();
		m_Fds[num] = (*iter)->getFd()->get();
		std::cout << "======================" << std::endl;
		std::cout << m_Hps[num] << std::endl;
		std::cout << m_Wps[num] << std::endl;
		std::cout << m_Mds[num] << std::endl;
		std::cout << m_Fds[num] << std::endl;
		std::cout <<"======================" << std::endl;

		num++;
	}
}
