#pragma once

#include"Command.h"
#include"Button.h"

class Cmd_SwatProductProcess : public ICommand {
public:
	Cmd_SwatProductProcess(Button* _button);
	~Cmd_SwatProductProcess();
	virtual void execute();
private:
	Button* m_Button;

};



