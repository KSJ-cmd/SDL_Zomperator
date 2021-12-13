#pragma once

#include"Command.h"
#include"Button.h"

class Cmd_SupplyProcess : public ICommand{
public:
	Cmd_SupplyProcess(Button* _button);
	~Cmd_SupplyProcess();
	virtual void execute();
private:
	Button* m_Button;

};





