#pragma once

#include"Command.h"
#include"Button.h"

class Cmd_SupplyEnd : public ICommand {
public:
	Cmd_SupplyEnd(Button* _button);
	~Cmd_SupplyEnd();
	virtual void execute();
private:
	Button* m_Button;

};





