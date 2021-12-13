


#include"Cmd_InvestmentProcess_Swat.h"
#include"Cmd_InvestmentEnd_Swat.h"
#include"Cmd_Investment_Swat.h"
#include"DataControl.h"
#include"Data.h"
#include"NationHandler.h"
#include<iostream>
Cmd_InvestmentProcess_Swat::Cmd_InvestmentProcess_Swat(Button* _button)
	:m_Button(_button)
{
}

Cmd_InvestmentProcess_Swat::~Cmd_InvestmentProcess_Swat()
{
}

void Cmd_InvestmentProcess_Swat::execute()
{
	std::cout << "Cmd_Investment_swat" << std::endl;
	for (std::vector<Nation*>::iterator iter = NationHandler::getNations().begin(); iter != NationHandler::getNations().end(); iter++) {
		Nation* target = *iter;
		target->getButton()->Active();
		target->setCommand(new Cmd_Investment_Swat(target));
	}
	m_Button->setCommand(new Cmd_InvestmentEnd_Swat(m_Button));
}