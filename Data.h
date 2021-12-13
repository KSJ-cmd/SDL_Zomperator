#pragma once
#include<iostream>
#include<vector>
#include"ResourceData.h"
#include"ProductData.h"
#include"SwatProductData.h"

class Data {
public:
	static Data* Instance();
	~Data();

	int getMoney() const;
	int getTurn() const;
	float getSwatSuccessRate() const;
	int getSwatInvestAmount(INVESTMENT _type) const;
	int getLimitNum() const;

	bool useMoney(int _val);
	void setSwatInvestAmount(INVESTMENT _type, int _Amount);
	void setSwatSuccessRate(float _val);
	void useLimitNum();
	bool CheckLimitNum();

	void TakeMoney();
	void resetLimitNum();
	void TurnEnd();


private:
	Data();
	Data(const Data& src);
	Data& operator=(const Data& rhs) {}

	static Data* p_Instance;
	
	int g_Money;
	int g_Turn;
	float g_SwatSuccessRate;
	std::vector<int>g_SwatInvestAmount;
	int g_LimitNum;

};