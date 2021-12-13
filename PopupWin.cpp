#include"PopupWin.h"
#include"TextureManager.h"
#include"Game.h"
PopupWin::PopupWin(const std::unique_ptr<LoaderParams*>& pParams, std::string _text)
	:Button(pParams),isType(true)
{
	SDL_Color white = { 255,255,255 };
	TextureManager::Instance()->loadText(_text, "PopupText", Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	std::cout << "PopupWin create" << std::endl;
}

PopupWin::PopupWin(const std::unique_ptr<LoaderParams*>& pParams, std::string _text, std::string _text2)
	:Button(pParams), isType(false)
{
	SDL_Color white = { 255,255,255 };
	TextureManager::Instance()->loadText(_text, "PopupText", Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	TextureManager::Instance()->loadText(_text2, "PopupText2", Game::Instance()->getRenderer(), Game::Instance()->getFont(), white);
	std::cout << "PopupWin create" << std::endl;
}

PopupWin::~PopupWin()
{
}

void PopupWin::draw()
{
	Button::draw();
	if (isType) {
		TextureManager::Instance()->drawQueryPivot("PopupText", 800, 450, Game::Instance()->getRenderer());
	}
	else {
		TextureManager::Instance()->drawQueryPivot("PopupText", 800, 430, Game::Instance()->getRenderer());
		TextureManager::Instance()->drawQueryPivot("PopupText2", 800, 480, Game::Instance()->getRenderer());
	}
}
