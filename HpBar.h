#pragma once
#include"Game.h"
class Nation;
class HpBar {
public:

	HpBar( const Vector2D& position, const Vector2D& area,Nation* _nation);
	HpBar(const HpBar& src) = default;
	HpBar& operator=(const HpBar& rsh) = default;


	void draw();
private:
	int m_maxHp;
	int m_curHp;
	float m_maxW;
	Nation* m_nation;
	SDL_Rect rect_bgHpbar;
	SDL_Rect rect_maxHpbar;
	SDL_Rect rect_curHpbar;
};