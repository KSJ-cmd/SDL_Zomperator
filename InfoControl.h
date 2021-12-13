#pragma once
#include"InfoData.h"
#include"InfoView.h"
#include"Window.h"
class Button;
class InfoControl :public Window {
public:
	InfoControl(const std::unique_ptr<LoaderParams*>& pParams);
	virtual ~InfoControl();

	virtual void update();
	virtual void draw();

	void drawINF();
	void loadINF();
private:
	InfoData* m_InfoData;
	InfoView* m_InfoView;
	Button* m_X_button;
};