#include "Cmd_UseResrc.h"
#include<iostream>
#include"Data.h"
#include"PopupWin.h"
#include"Cmd_Xbutton.h"

Cmd_UseResrc::Cmd_UseResrc(Nation* _Nation, IUse* _use, ITake* _take, ITake* _take_hp)
	: m_Nation(_Nation),m_Use(_use), m_Take(_take), m_TakeHP(_take_hp)
{
}

Cmd_UseResrc::~Cmd_UseResrc()
{
}

void Cmd_UseResrc::execute()
{
	std::cout << "Cmd_UseResrc execute" << std::endl;
	if (Data::Instance()->CheckLimitNum() && m_Nation->getAlive() && m_Use->Use()) {
		Data::Instance()->useLimitNum();
		m_Take->Take();
		m_TakeHP->Take();
		std::unique_ptr<LoaderParams*> p_loader_popup = std::make_unique<LoaderParams*>(new LoaderParams(447, 239, 1600, 900, "message_bor_0", "message_bor_0"));
		std::string message1 = m_Nation->getTag() + " Healing";
		std::string message2 = " HP : " + std::to_string(m_Nation->getHp()->get())
			+ " WP : " + std::to_string(m_Nation->getWp()->get())
			+ " FD : " + std::to_string(m_Nation->getFd()->get())
			+ " MD : " + std::to_string(m_Nation->getMd()->get());
		PopupWin* popupWin = new PopupWin(p_loader_popup, message1, message2);
		popupWin->setCommand(new Cmd_Xbutton(popupWin));
		popupWin->setScale(Vector2D(0.8, 0.8));
	}
}
