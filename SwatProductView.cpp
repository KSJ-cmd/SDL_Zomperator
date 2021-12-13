#include"TextureManager.h"
#include"Game.h"
#include"SwatProductView.h"

SwatProductView::SwatProductView(const std::unique_ptr<LoaderParams*>& pParams
	, SwatProductViewModel* _SwatProductViewModel, INVESTMENT _Type)
	:Button(pParams),m_SwatProductViewModel(_SwatProductViewModel),m_Type(_Type)
	,m_AmountID((int)_Type+"AmountID")
{
	SDL_Color white = { 255,255,255,255 };
	std::string Amount = m_SwatProductViewModel->get(m_Type)->getAmount_Str();
	TextureManager::Instance()->loadText(Amount, m_AmountID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);

}

SwatProductView::~SwatProductView()
{
}

void SwatProductView::DataInsert(SwatProductData* _Data)
{
	m_SwatProductViewModel->DataInsert(_Data);
}

void SwatProductView::draw()
{
	SDL_Color white = { 255,255,255,255 };
	std::string Amount = m_SwatProductViewModel->get(m_Type)->getAmount_Str();

	TextureManager::Instance()->loadText(Amount, m_AmountID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);

	TextureManager::Instance()->drawQuery(m_AmountID, m_position.getX(), m_position.getY(), Game::Instance()->getRenderer());

}
