#pragma once

#include"Command.h"
#include"Button.h"
#include"SwatProductData.h"
class Cmd_Investment_ReSource : public ICommand {
public:
	Cmd_Investment_ReSource(Button* _button, SwatProductData* _SwatProductData);
	~Cmd_Investment_ReSource();
	virtual void execute();
private:
	Button* m_Button;
	SwatProductData* m_SwatProductData;

};



