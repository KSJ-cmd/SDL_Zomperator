#include "Fade.h"
#include"TextureManager.h"
#include"Playroom.h"
Fade::Fade(const std::unique_ptr<LoaderParams*>& pParams)
	:Button(pParams), m_Alpha(255)
{
}

Fade::~Fade()
{
}

void Fade::update()
{
	
}

void Fade::draw()
{
	std::cout << m_Alpha << std::endl;
	Button::draw();
	TextureManager::Instance()->BlendAlpha(m_Alpha, m_textureID);
	SDL_Delay(50);

}

void Fade::ApplyAlpha(int _val)
{
	if (m_Alpha > 0) {
		m_Alpha -= _val;
	}
}

int Fade::getAlpha() const
{
	return m_Alpha;
}
