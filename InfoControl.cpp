#include<string>
#include "InfoControl.h"
#include"TextureManager.h"
#include"Game.h"
#include"Cmd_Xbutton.h"


InfoControl::InfoControl(const std::unique_ptr<LoaderParams*>& pParams)
	:Window(pParams)
	,m_InfoData(new InfoData())
	, m_InfoView(new InfoView())
	, m_X_button(nullptr)
{
	loadINF();
	std::unique_ptr<LoaderParams*> button_X = std::make_unique<LoaderParams*>(new LoaderParams(0, 0,1600,900, "", "X_button"));
	m_X_button = new Button(button_X);
	m_X_button->setCommand(new Cmd_Xbutton(this));
}

InfoControl::~InfoControl()
{
	std::cout << "infoControl delete" << std::endl;
	delete m_InfoData;
	delete m_InfoView;
	std::cout << m_X_button << std::endl;
	delete m_X_button;
	std::cout << m_X_button << std::endl;
}

void InfoControl::update()
{
}

void InfoControl::draw()
{
	Window::draw();
	m_InfoView->drawINF(m_InfoData);
}
void InfoControl::drawINF()
{
	int num = 0;

	for (std::vector<int>::iterator iter_data(m_InfoData->getHps().begin()); iter_data != m_InfoData->getHps().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationHp" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 450, 190 + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(m_InfoData->getWps().begin()); iter_data != m_InfoData->getWps().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationWp" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 550, 190 + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(m_InfoData->getMds().begin()); iter_data != m_InfoData->getMds().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationMd" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 550, 190 + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(m_InfoData->getFds().begin()); iter_data != m_InfoData->getFds().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationFd" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 550, 190 + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
}

void InfoControl::loadINF()
{
	int num = 0;
	SDL_Color white = { 255,255,255,255 };

	for (std::vector<int>::iterator iter_data(m_InfoData->getHps().begin()); iter_data != m_InfoData->getHps().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationHp" + std::to_string(num);
		num++;
		//std::cout << id << std::endl;
		TextureManager::Instance()->loadText(hp, id, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(m_InfoData->getWps().begin()); iter_data != m_InfoData->getWps().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationWp" + std::to_string(num);
		num++;
		//std::cout << id << std::endl;
		TextureManager::Instance()->loadText(hp, id, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(m_InfoData->getMds().begin()); iter_data != m_InfoData->getMds().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationMd" + std::to_string(num);
		num++;
		//std::cout << id << std::endl;
		TextureManager::Instance()->loadText(hp, id, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(m_InfoData->getFds().begin()); iter_data != m_InfoData->getFds().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationFd" + std::to_string(num);
		num++;
		//std::cout << id << std::endl;
		TextureManager::Instance()->loadText(hp, id, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	}
	num = 0;
}
