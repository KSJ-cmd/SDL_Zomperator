#include"Window.h"
#include"Playroom.h"
#include"TextureManager.h"
Window::Window(const std::unique_ptr<LoaderParams*>& pParams)
	:SDLGameObject(pParams)
{
	Playroom::getWindows().push_back(this);
}

Window::~Window()
{
	Playroom::getWindows().remove(this);
}

void Window::update()
{
}

void Window::draw()
{
	SDLGameObject::draw();
}

