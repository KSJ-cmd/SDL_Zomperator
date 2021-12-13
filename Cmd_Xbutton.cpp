#include"Cmd_Xbutton.h"
#include"SDLGameObject.h"
#include<iostream>
Cmd_Xbutton::Cmd_Xbutton(SDLGameObject* _deleteTarget)
	:m_deleteTarget(_deleteTarget), m_deleteTargets(1)
{
	
}

Cmd_Xbutton::~Cmd_Xbutton()
{
	m_deleteTargets.clear();
	m_deleteTargets.shrink_to_fit();
	std::cout << "Cmd_Xbutton delete" << std::endl;
}

void Cmd_Xbutton::execute()
{
	
	for (SDLGameObject* i : m_deleteTargets) {
		delete i;
	}
	delete m_deleteTarget;
	std::cout << "Cmd_Xbutton" << std::endl;
	
}

void Cmd_Xbutton::insertTarget(SDLGameObject* _deleteTarget)
{
	m_deleteTargets.push_back(_deleteTarget);
}

