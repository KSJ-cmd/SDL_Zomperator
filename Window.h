#pragma once
#include"SDLGameObject.h"
class Window : public SDLGameObject {
public:
	Window(const std::unique_ptr<LoaderParams*>& pParams);
	virtual ~Window();
	virtual void update();
	virtual void draw();
private:
};

