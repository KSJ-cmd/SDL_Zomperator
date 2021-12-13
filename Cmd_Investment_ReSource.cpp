#include"Cmd_Investment_ReSource.h"
#include"DataControl.h"
#include"Data.h"
#include<iostream>
Cmd_Investment_ReSource::Cmd_Investment_ReSource(Button* _button, SwatProductData* _SwatProductData)
	:m_Button(_button), m_SwatProductData(_SwatProductData)
{
}

Cmd_Investment_ReSource::~Cmd_Investment_ReSource()
{
}

void Cmd_Investment_ReSource::execute()
{
	//DataControl::Instance()->get();
	std::cout << "Cmd_Investment" << std::endl;
	switch (m_SwatProductData->getType())
	{
	case INVESTMENT::WP:
		if(DataControl::Instance()->get()->getWP()->Use()){
			m_SwatProductData->Invest();
			Data::Instance()->setSwatInvestAmount(m_SwatProductData->getType(), m_SwatProductData->getAmount());
			Data::Instance()->setSwatSuccessRate(Data::Instance()->getSwatSuccessRate() + 3.3);
		}
		break;
	case INVESTMENT::FD:
		if (DataControl::Instance()->get()->getFD()->Use()) {
			m_SwatProductData->Invest();
			Data::Instance()->setSwatInvestAmount(m_SwatProductData->getType(), m_SwatProductData->getAmount());
			Data::Instance()->setSwatSuccessRate(Data::Instance()->getSwatSuccessRate() + 2.4);
		}
		break;
	case INVESTMENT::MD:
		if (DataControl::Instance()->get()->getMD()->Use()) {
			m_SwatProductData->Invest();
			Data::Instance()->setSwatInvestAmount(m_SwatProductData->getType(), m_SwatProductData->getAmount());
			Data::Instance()->setSwatSuccessRate(Data::Instance()->getSwatSuccessRate() + 1.7);
		}
		break;
	default:
		break;
	}

}
