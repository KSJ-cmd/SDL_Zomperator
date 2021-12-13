#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"DataControl.h"
#include"Button.h"

class SwatRateView :public Button {
public:
	SwatRateView(const std::unique_ptr<LoaderParams*>& pParams);
	SwatRateView(const SwatRateView& src);
	~SwatRateView();
	virtual void draw();
	void Notify();

private:
	SDL_Renderer* m_Renderer;
	TTF_Font* m_Font;

	std::string str_SwatRate;
};