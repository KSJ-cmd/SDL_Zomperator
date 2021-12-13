#include<iostream>
#include "Cmd_SupplyEnd.h"
#include"Cmd_SupplyProcess.h"
#include"NationHandler.h"
#include"Button.h"
#include"Cmd_UseResrc.h"
#include"DataControl.h"
Cmd_SupplyProcess::Cmd_SupplyProcess(Button* _button)
	:m_Button(_button)
{
}

Cmd_SupplyProcess::~Cmd_SupplyProcess()
{
}

void Cmd_SupplyProcess::execute()
{
	for (std::vector<Nation*>::iterator iter = NationHandler::getNations().begin(); iter != NationHandler::getNations().end(); iter++) {
		Nation* target = *iter;
		target->getButton()->Active();
		switch (m_Button->getSupplyType()) {
		case SUPPLYTYPE::WP:
			target->setCommand(new Cmd_UseResrc(target, DataControl::Instance()->get()->getWP(), target->getWp(), target->getHp()));
			break;
		case SUPPLYTYPE::FD:
			target->setCommand(new Cmd_UseResrc(target, DataControl::Instance()->get()->getFD(), target->getFd(), target->getHp()));
			break;
		case SUPPLYTYPE::MD:
			target->setCommand(new Cmd_UseResrc(target, DataControl::Instance()->get()->getMD(), target->getMd(), target->getHp()));
			break;
		default:
			std::cout << "SUPPLETYPE error" << std::endl;
			break;
		}
	}
	m_Button->TransTexture(BUTTONSTATE::PROCESS);
	m_Button->setCommand(new Cmd_SupplyEnd(m_Button));
}



