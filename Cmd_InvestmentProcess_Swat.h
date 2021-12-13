#pragma once
#include"Command.h"
#include"Button.h"
#include"Data.h"

class Cmd_InvestmentProcess_Swat : public ICommand {
public:
	Cmd_InvestmentProcess_Swat(Button* _button);
	~Cmd_InvestmentProcess_Swat();
	virtual void execute();
private:
	Button* m_Button;
};