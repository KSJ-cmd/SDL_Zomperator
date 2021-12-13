#pragma once

#include"Command.h"
#include"Nation.h"
#include"Use.h"
#include"Take.h"
class Cmd_UseResrc : public ICommand {
public:
	Cmd_UseResrc(Nation* _Nation,IUse* _use, ITake* _take, ITake* _take_hp);
	~Cmd_UseResrc();
	virtual void execute();
private:
	Nation* m_Nation;
	IUse* m_Use;
	ITake* m_Take;
	ITake* m_TakeHP;
};