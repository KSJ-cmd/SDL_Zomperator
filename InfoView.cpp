#include<string>
#include"InfoView.h"
#include"Playroom.h"
#include"TextureManager.h"
#include"Game.h"

InfoView::InfoView()
{
	
}

InfoView::~InfoView()
{
	std::cout << "InfoView delete " << std::endl;
}



void InfoView::drawINF(InfoData* _infoData)
{
	int num = 0;
	int y = 160;
	for (std::vector<int>::iterator iter_data(_infoData->getHps().begin()); iter_data != _infoData->getHps().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationHp" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 380, y + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(_infoData->getWps().begin()); iter_data != _infoData->getWps().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationWp" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 500, y + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(_infoData->getMds().begin()); iter_data != _infoData->getMds().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationMd" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 610, y + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
	for (std::vector<int>::iterator iter_data(_infoData->getFds().begin()); iter_data != _infoData->getFds().end(); iter_data++) {
		std::string hp = std::to_string(*iter_data);
		std::string id = "NationFd" + std::to_string(num);
		//std::cout << id << std::endl;
		TextureManager::Instance()->drawQuery(id, 730, y + (num * 80), Game::Instance()->getRenderer());
		num++;
	}
	num = 0;
}
