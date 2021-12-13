#include<string>
#include"SwatRateView.h"
#include"TextureManager.h"
#include"Game.h"
#include"Data.h"
SwatRateView::SwatRateView(const std::unique_ptr<LoaderParams*>& pParams)
	:Button(pParams)
	,m_Renderer(Game::Instance()->getRenderer())
	, m_Font(Game::Instance()->getFont())
	, str_SwatRate(std::to_string((int)Data::Instance()->getSwatSuccessRate()) + "%")

{
	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(str_SwatRate, "swatRate", m_Renderer, m_Font, white);
}

SwatRateView::SwatRateView(const SwatRateView& src)
	:Button(src)
	,m_Renderer(Game::Instance()->getRenderer())
	, m_Font(Game::Instance()->getFont())
{

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(src.str_SwatRate, "swatRate", m_Renderer, m_Font, white);

}

SwatRateView::~SwatRateView()
{
}

void SwatRateView::draw()
{
	TextureManager::Instance()->drawQuery("swatRate", 875, 195, m_Renderer);

	Notify();
}
//Subject¿¡ push_back
void SwatRateView::Notify()
{
	str_SwatRate = std::to_string((int)Data::Instance()->getSwatSuccessRate())+"%";

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(str_SwatRate, "swatRate", m_Renderer, m_Font, white);

}

