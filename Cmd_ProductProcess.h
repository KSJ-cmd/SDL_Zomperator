#pragma once

#include"Command.h"
#include"Button.h"

class Cmd_ProductProcess : public ICommand {
public:
	Cmd_ProductProcess(Button* _button);
	~Cmd_ProductProcess();
	virtual void execute();
private:
	Button* m_Button;

};



