#pragma once

#include"Button.h"
#include"Command.h"
#include"Nation.h"

class Cmd_Investment_Swat : public ICommand{
public:
	Cmd_Investment_Swat(Nation* _Nation);
	~Cmd_Investment_Swat();
	virtual void execute();
private:
	Nation* m_Nation;
};