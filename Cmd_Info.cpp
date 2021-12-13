#include"Cmd_Info.h"
#include"InfoControl.h"
#include<memory>
#include<iostream>
Cmd_Info::Cmd_Info()
{
}

Cmd_Info::~Cmd_Info()
{
	std::cout << "cmd_info delete" << std::endl;
}

void Cmd_Info::execute()
{
	std::unique_ptr<LoaderParams*> p_loader = std::make_unique<LoaderParams*>(new LoaderParams(0, 0, "inf_bg_spr_0", "inf_bg_spr_0"));
	std::unique_ptr<InfoControl*> p_info = std::make_unique<InfoControl*>(new InfoControl(p_loader));
	std::cout << "InfoControl create" << std::endl;
}
