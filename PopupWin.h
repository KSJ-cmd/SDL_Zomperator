#pragma once
#include"Button.h"
#include<string>
class PopupWin :public Button {
public:
	PopupWin(const std::unique_ptr<LoaderParams*>& pParams, std::string _text);
	PopupWin(const std::unique_ptr<LoaderParams*>& pParams, std::string _text, std::string _text2);
	~PopupWin();
	virtual void draw();
private:
	bool isType;
};