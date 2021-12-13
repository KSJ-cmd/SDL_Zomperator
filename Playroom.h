#pragma once
#include<iostream>
#include<vector>
#include<list>
#include"Scene.h"
#include"ButtonHandler.h"
#include"NationHandler.h"
#include"DataControl.h"
#include"Window.h"

class Playroom : public Scene {
public:
	Playroom(std::string name);
	~Playroom();
	virtual void update();
	virtual void draw();
	void handleInput();
	void ButtonClickCheck();
	DataControl& getData() const;

	static std::vector<SDLGameObject*>& getGameObjects();
	static std::list<Button*>& getButtons();
	static std::list<Window*>& getWindows();
private:
	std::string _name;
	bool isClick;
	ButtonHandler* _buttonHandler;
	NationHandler* _nationHandler;
	DataControl* _dataControl;

	static std::vector<SDLGameObject*> m_bgObjects;
	static std::vector<SDLGameObject*> m_gameObjects;
	static std::list<Button*> m_ButtonObjects;
	static std::list<Window*> m_WindowObjects;

};

