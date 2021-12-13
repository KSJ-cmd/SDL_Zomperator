#pragma once
#include"Command.h"

class Cmd_Info : public ICommand {
public:
	Cmd_Info();
	~Cmd_Info();
	void execute();
private:
};