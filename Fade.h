#pragma once
#include"Button.h"

class Fade :public Button {
public:
	Fade(const std::unique_ptr<LoaderParams*>& pParams);
	virtual ~Fade();
	virtual void update();
	virtual void draw();
	void ApplyAlpha(int _val);
	int getAlpha() const;
private:
	int m_Alpha;
};