#include<iostream>
#include "Cmd_InvestmentEnd_Swat.h"
#include"Cmd_InvestmentProcess_Swat.h"
#include"NationHandler.h"

Cmd_InvestmentEnd_Swat::Cmd_InvestmentEnd_Swat(Button* _button)
	:m_Button(_button)
{
}

Cmd_InvestmentEnd_Swat::~Cmd_InvestmentEnd_Swat()
{
}

void Cmd_InvestmentEnd_Swat::execute()
{

	for (std::vector<Nation*>::iterator iter = NationHandler::getNations().begin(); iter != NationHandler::getNations().end(); iter++) {
		Nation* target = *iter;
		target->getButton()->InActive();
		target->setCommand(nullptr);
	}

	m_Button->setCommand(new Cmd_InvestmentProcess_Swat(m_Button));
}
