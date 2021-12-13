#include<iostream>
#include"NationHandler.h"
#include"Button.h"
#include"Cmd_UseResrc.h"
#include"DataControl.h"
#include "Cmd_SupplyEnd.h"
#include"Cmd_SupplyProcess.h"
Cmd_SupplyEnd::Cmd_SupplyEnd(Button* _button)
	:m_Button(_button)
{
}

Cmd_SupplyEnd::~Cmd_SupplyEnd()
{
}

void Cmd_SupplyEnd::execute()
{
	for (std::vector<Nation*>::iterator iter = NationHandler::getNations().begin(); iter != NationHandler::getNations().end(); iter++) {
		Nation* target = *iter;
		target->getButton()->InActive();
		switch (m_Button->getSupplyType()) {
		case SUPPLYTYPE::WP:
			target->setCommand(nullptr);
			break;
		case SUPPLYTYPE::MD:
			target->setCommand(nullptr);
			break;
		case SUPPLYTYPE::FD:
			target->setCommand(nullptr);
			break;
		default:
			std::cout << "SUPPLETYPE error" << std::endl;
			break;
		}
	}
	m_Button->TransTexture(BUTTONSTATE::IDLE);
	m_Button->setCommand(new Cmd_SupplyProcess(m_Button));
}
