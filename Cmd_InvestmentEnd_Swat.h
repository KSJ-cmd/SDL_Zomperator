#pragma once

#include"Command.h"
#include"Button.h"

class Cmd_InvestmentEnd_Swat : public ICommand {
public:
	Cmd_InvestmentEnd_Swat(Button* _button);
	~Cmd_InvestmentEnd_Swat();
	virtual void execute();
private:
	Button* m_Button;

};
