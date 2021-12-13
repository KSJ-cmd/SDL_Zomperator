#include"SwatProductData.h"
#include"Data.h"

SwatProductData::SwatProductData(INVESTMENT _Type)
	:m_Type(_Type),m_InvestAmount(Data::Instance()->getSwatInvestAmount(m_Type))
	,m_InvestAmount_str(std::to_string(m_InvestAmount))
{

}

SwatProductData::SwatProductData(const SwatProductData& src)
	: m_Type(src.m_Type), m_InvestAmount(src.m_InvestAmount)
	,m_InvestAmount_str(src.m_InvestAmount_str)
{
}

SwatProductData::~SwatProductData()
{
	Data::Instance()->setSwatInvestAmount(m_Type, m_InvestAmount);
}

INVESTMENT SwatProductData::getType() const
{
	return m_Type;
}

int SwatProductData::getAmount() const
{
	return m_InvestAmount;
}

std::string SwatProductData::getAmount_Str() const
{
	return m_InvestAmount_str;
}

bool SwatProductData::Invest()
{
	m_InvestAmount++;
	m_InvestAmount_str = std::to_string(m_InvestAmount);
	return true;
}
