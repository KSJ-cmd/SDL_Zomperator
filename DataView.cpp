#include<string>
#include"DataView.h"
#include"DataControl.h"
#include"TextureManager.h"
#include"Game.h"
#include"Data.h"
DataView::DataView(DataControl* DataControl)
	:m_DataControl(DataControl), m_Renderer(Game::Instance()->getRenderer())
	, m_Font(Game::Instance()->getFont())
	, str_weaponAmount(std::to_string(m_DataControl->get()->getWP()->get()))
	, str_medicineAmount(std::to_string(m_DataControl->get()->getMD()->get()))
	, str_foodAmount(std::to_string(m_DataControl->get()->getFD()->get()))
	, str_Turn(std::to_string(Data::Instance()->getTurn()))
	, str_Money(std::to_string(Data::Instance()->getMoney()))
	, str_LimitNum(std::to_string(Data::Instance()->getLimitNum()))
{
	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(str_weaponAmount, "wpAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_foodAmount, "fdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_medicineAmount, "mdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_Turn, "Turn", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_Money, "Money", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_LimitNum, "LimitNum", m_Renderer, m_Font, white);


}

DataView::DataView(const DataView& src)
	:m_DataControl(src.m_DataControl), m_Renderer(Game::Instance()->getRenderer())
	, m_Font(Game::Instance()->getFont())
	
{

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(src.str_weaponAmount, "wpAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_foodAmount, "fdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_medicineAmount, "mdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_Turn, "Turn", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_Money, "Money", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_LimitNum, "LimitNum", m_Renderer, m_Font, white);
}

DataView::~DataView()
{
}

void DataView::Draw()
{
	TextureManager::Instance()->drawQuery("wpAmount", 610, 682, m_Renderer);
	TextureManager::Instance()->drawQuery("fdAmount", 884, 682, m_Renderer);
	TextureManager::Instance()->drawQuery("mdAmount", 1160, 682, m_Renderer);
	TextureManager::Instance()->drawQuery("Turn", 1105, 160, m_Renderer);
	TextureManager::Instance()->drawQuery("Money", 1030, 210, m_Renderer);
	TextureManager::Instance()->drawQuery("LimitNum", 795, 140, m_Renderer);

	Notify();
}
//Subject¿¡ push_back
void DataView::Notify()
{
	str_weaponAmount = std::to_string(m_DataControl->get()->getWP()->get());
	str_foodAmount = std::to_string(m_DataControl->get()->getFD()->get());
	str_medicineAmount = std::to_string(m_DataControl->get()->getMD()->get());
	str_Turn = std::to_string(Data::Instance()->getTurn());
	str_Money = std::to_string(Data::Instance()->getMoney());
	str_LimitNum = std::to_string(Data::Instance()->getLimitNum());

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(str_weaponAmount, "wpAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_foodAmount, "fdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_medicineAmount, "mdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_Turn, "Turn", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_Money, "Money", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_LimitNum, "LimitNum", m_Renderer, m_Font, white);
}

