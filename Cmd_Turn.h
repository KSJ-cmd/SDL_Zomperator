#pragma once
#include"Command.h"
#include"Button.h"

class Cmd_Turn : public ICommand {
public:
	Cmd_Turn(Button* _button);
	~Cmd_Turn();
	virtual void execute();
private:
	Button* m_Button;
};