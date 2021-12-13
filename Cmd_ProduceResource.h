#pragma once

#include"Command.h"
#include"Button.h"
#include"ProductData.h"

class Cmd_ProduceResource : public ICommand {
public:
	Cmd_ProduceResource(Button* _button,ProductData* _ProductData);
	~Cmd_ProduceResource();
	virtual void execute();
private:
	Button* m_Button;
	ProductData* m_ProductData;
};



