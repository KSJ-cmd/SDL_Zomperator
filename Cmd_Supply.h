#pragma once

#include"Command.h"
#include"Use.h"
#include"Take.h"
class Cmd_Supply : public ICommand{
public:
	Cmd_Supply(IUse* _use, ITake* _take);
	~Cmd_Supply();
	void execute();
private:
	 IUse* m_use;
	 ITake* m_Take;
};