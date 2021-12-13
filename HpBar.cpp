#include"Game.h"
#include "HpBar.h"
#include"Nation.h"
const int MAX = 100;
const int MIN = 0;
const int INTER = 2;

HpBar::HpBar(const Vector2D& position, const Vector2D& area,Nation* _nation)
	:m_maxHp(MAX),m_maxW(area.getX()),m_nation(_nation)
{
	rect_bgHpbar.x = static_cast<int>(position.getX() - INTER);
	rect_bgHpbar.y = static_cast<int>(position.getY() - INTER);
	rect_bgHpbar.w = static_cast<int>(area.getX() + (INTER * 2));
	rect_bgHpbar.h = static_cast<int>(area.getY() + (INTER * 2));

	rect_maxHpbar.x = static_cast<int>(position.getX() - (INTER / 2));
	rect_maxHpbar.y = static_cast<int>(position.getY() - (INTER / 2));
	rect_maxHpbar.w = static_cast<int> (area.getX() + INTER);
	rect_maxHpbar.h = static_cast<int>(area.getY() + INTER);

	rect_curHpbar.x = static_cast<int>(position.getX());
	rect_curHpbar.y = static_cast<int>(position.getY());
	rect_curHpbar.w = static_cast<int>(area.getX() * m_nation->getHp()->get() / 100);
	rect_curHpbar.h = static_cast<int>(area.getY());
}

void HpBar::draw()
{
	rect_curHpbar.w = static_cast<int>((m_maxW * m_nation->getHp()->get())/100);

	SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 0, 0, 0, 255);
	SDL_RenderFillRect(Game::Instance()->getRenderer(), &rect_bgHpbar);

	SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 255, 0, 0, 255);
	SDL_RenderFillRect(Game::Instance()->getRenderer(), &rect_maxHpbar);
	
	SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 0, 0, 255, 255);
	SDL_RenderFillRect(Game::Instance()->getRenderer(), &rect_curHpbar);
}
