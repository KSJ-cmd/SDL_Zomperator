#pragma once
#include<vector>
#include"Command.h"
class SDLGameObject;
class Cmd_Xbutton : public ICommand {
public:
	Cmd_Xbutton(SDLGameObject* _deleteTarget);
	~Cmd_Xbutton();
	virtual void execute();
	void insertTarget(SDLGameObject* _deleteTarget);
private:
	SDLGameObject* m_deleteTarget;
	std::vector<SDLGameObject*> m_deleteTargets;
};