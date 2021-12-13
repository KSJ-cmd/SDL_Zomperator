#include<string>
#include"SwatDataView.h"
#include"DataControl.h"
#include"TextureManager.h"
#include"Game.h"
SwatDataView::SwatDataView(const std::unique_ptr<LoaderParams*>& pParams)
	:Button(pParams),
	m_DataControl(DataControl::Instance()), m_Renderer(Game::Instance()->getRenderer())
	, m_Font(Game::Instance()->getFont())
	, str_weaponAmount(std::to_string(m_DataControl->get()->getWP()->get()))
	, str_medicineAmount(std::to_string(m_DataControl->get()->getMD()->get()))
	, str_foodAmount(std::to_string(m_DataControl->get()->getFD()->get()))
{
	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(str_weaponAmount, "swatwpAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_foodAmount, "swatfdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_medicineAmount, "swatmdAmount", m_Renderer, m_Font, white);

	std::cout << "swatdataview " << str_weaponAmount << std::endl;

}

SwatDataView::SwatDataView(const SwatDataView& src)
	:Button(src),
	m_DataControl(src.m_DataControl), m_Renderer(Game::Instance()->getRenderer())
	, m_Font(Game::Instance()->getFont())
{

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(src.str_weaponAmount, "swatwpAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_foodAmount, "swatfdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(src.str_medicineAmount, "swatmdAmount", m_Renderer, m_Font, white);
}

SwatDataView::~SwatDataView()
{
}

void SwatDataView::draw()
{
	TextureManager::Instance()->drawQuery("swatwpAmount", 876, 339, m_Renderer);
	TextureManager::Instance()->drawQuery("swatfdAmount", 876, 443, m_Renderer);
	TextureManager::Instance()->drawQuery("swatmdAmount", 876, 549, m_Renderer);
	Notify();
}
//Subject¿¡ push_back
void SwatDataView::Notify()
{
	str_weaponAmount = std::to_string(m_DataControl->get()->getWP()->get());
	str_foodAmount = std::to_string(m_DataControl->get()->getFD()->get());
	str_medicineAmount = std::to_string(m_DataControl->get()->getMD()->get());

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(str_weaponAmount, "swatwpAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_foodAmount, "swatfdAmount", m_Renderer, m_Font, white);
	TextureManager::Instance()->loadText(str_medicineAmount, "swatmdAmount", m_Renderer, m_Font, white);
}

