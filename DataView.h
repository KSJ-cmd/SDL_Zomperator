#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include"DataControl.h"
#include"Observer.h"

class DataView {
public:
	DataView(DataControl* DataControl);
	DataView(const DataView& src);
	~DataView();
	void Draw();
	void Notify();

private:
	DataControl* m_DataControl;
	SDL_Renderer* m_Renderer;
	TTF_Font* m_Font;

	std::string str_weaponAmount;
	std::string str_medicineAmount;
	std::string str_foodAmount;
	std::string str_Turn;
	std::string str_Money;
	std::string str_LimitNum;
};