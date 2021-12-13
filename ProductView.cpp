#include "ProductView.h"
#include"Game.h"
#include"TextureManager.h"


ProductView::ProductView(ProductData* _data, const std::unique_ptr<LoaderParams*>& pParams, Vector2D _TextVecPrice,Vector2D _TextVecAmount)
	: Button(pParams),m_ProductViewModel(new ProductViewModel(_data))
	,m_strPrice(std::to_string(m_ProductViewModel->getPrice())), m_strAmount(std::to_string(m_ProductViewModel->getAmount()))
	,m_TextVecPrice(_TextVecPrice), m_TextVecAmount(_TextVecAmount)
{
	SDL_Color white = { 255,255,255,255 };
	m_strPriceID = std::to_string((int)m_ProductViewModel->getType()) + "Price";
	m_strAmountID = std::to_string((int)m_ProductViewModel->getType()) + "Amount";
	std::cout << m_strPriceID << std::endl;
		//m_ProductViewModel->getPrice()

	TextureManager::Instance()->loadText(m_strPrice ,m_strPriceID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	TextureManager::Instance()->loadText(m_strAmount, m_strAmountID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
}

ProductView::ProductView(const ProductView& src)
	: Button(std::make_unique<LoaderParams*>(new LoaderParams(src.m_position.getX(), src.m_position.getY(), src.m_width,src.m_height,src.m_textureID,src.getTag())))
	,m_ProductViewModel(new ProductViewModel(*src.m_ProductViewModel))
	, m_TextVecPrice(src.m_TextVecPrice), m_TextVecAmount(src.m_TextVecAmount)
{
	SDL_Color white = { 255,255,255,255 };
	m_strPriceID = std::to_string((int)m_ProductViewModel->getType()) + "Price";
	m_strAmountID = std::to_string((int)m_ProductViewModel->getType()) + "Amount";

	TextureManager::Instance()->loadText(m_strPrice, m_strPriceID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	TextureManager::Instance()->loadText(m_strAmount, m_strAmountID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
}

void ProductView::draw()
{
	Button::draw();
	//str_Amount = std::to_string(m_ProductViewModel->getAmount());
	m_strPrice = std::to_string(m_ProductViewModel->getPrice());
	m_strAmount = std::to_string(m_ProductViewModel->getAmount());

	SDL_Color white = { 255,255,255,255 };
	TextureManager::Instance()->loadText(m_strPrice, m_strPriceID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	TextureManager::Instance()->loadText(m_strAmount, m_strAmountID, Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);

	TextureManager::Instance()->drawQuery(m_strPriceID, m_TextVecPrice.getX(), m_TextVecPrice.getY(), Game::Instance()->getRenderer());
	TextureManager::Instance()->drawQuery(m_strAmountID, m_TextVecAmount.getX(), m_TextVecAmount.getY(), Game::Instance()->getRenderer());
}
