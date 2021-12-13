#include"Data.h"
#include<algorithm>
#include"Game.h"
#include"PlayroomHandler.h"
const int cnt_money = 100;

Data* Data::p_Instance = nullptr;


Data* Data::Instance()
{
	if (p_Instance == nullptr) {
		p_Instance = new Data();
	}
	return p_Instance;
}

Data::~Data()
{
	delete p_Instance;
	
}
int Data::getMoney() const
{
	return g_Money;
}
int Data::getTurn() const
{
	return g_Turn;
}
float Data::getSwatSuccessRate() const
{
	return g_SwatSuccessRate;
}
int Data::getSwatInvestAmount(INVESTMENT _type) const
{
	return g_SwatInvestAmount[(int)_type];
}
int Data::getLimitNum() const
{
	return g_LimitNum;
}
bool Data::useMoney(int _val)
{
	std::cout <<"money : " << g_Money << std::endl;
	if (g_Money < _val) {
		return false;
	}
	else {
		g_Money -= _val;
		return true;
	}
	
}
void Data::setSwatInvestAmount(INVESTMENT _type, int _Amount)
{
	g_SwatInvestAmount[(int)_type] = _Amount;
}
void Data::setSwatSuccessRate(float _val)
{
	this->g_SwatSuccessRate = _val;
	
}

void Data::useLimitNum()
{
	g_LimitNum--;
}

bool Data::CheckLimitNum()
{
	if (g_LimitNum > 0) {
		return true;
	}
	else {
		return false;
	}
}
void Data::TakeMoney()
{
	g_Money += (g_Turn * cnt_money) * std::sqrt(g_Turn);
}
void Data::resetLimitNum()
{
	g_LimitNum = 3;
}
void Data::TurnEnd()
{
	if (g_Turn < 20) {
		g_Turn++;
	}
	else {
		Game::Instance()->quit();
	}
}

Data::Data()
	:g_Money(1000),g_Turn(1),g_SwatSuccessRate(0),g_SwatInvestAmount(3,0),g_LimitNum(3)
{
	std::cout << "Data create" << std::endl;
}

Data::Data(const Data& src)
	: g_Money(src.g_Money), g_Turn(src.g_Turn), g_SwatSuccessRate(src.g_SwatSuccessRate), g_SwatInvestAmount(src.g_SwatInvestAmount), g_LimitNum(src.g_LimitNum)
{
	std::cout << "Data copy create" << std::endl;
}
