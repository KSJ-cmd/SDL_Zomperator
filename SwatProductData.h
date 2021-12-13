#pragma once
#include<iostream>
#include<string>
enum class INVESTMENT
{
	WP = 0, FD, MD
};

class SwatProductData {
public:
	SwatProductData(INVESTMENT _Type);
	SwatProductData(const SwatProductData& src);
	~SwatProductData();

	INVESTMENT getType() const;
	int getAmount() const;
	std::string getAmount_Str() const;

	bool Invest();
private:
	INVESTMENT m_Type;
	int m_InvestAmount;
	std::string m_InvestAmount_str;
};