#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"DataControl.h"
#include"Button.h"

class SwatDataView :public Button {
public:
	SwatDataView(const std::unique_ptr<LoaderParams*>& pParams);
	SwatDataView(const SwatDataView& src);
	~SwatDataView();
	virtual void draw();
	void Notify();

private:
	DataControl* m_DataControl;
	SDL_Renderer* m_Renderer;
	TTF_Font* m_Font;

	std::string str_weaponAmount;
	std::string str_medicineAmount;
	std::string str_foodAmount;
};