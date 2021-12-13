#include"LoaderParams.h"
#include"TextureManager.h"

LoaderParams::LoaderParams(int x, int y, int width, int height, std::string textureID, std::string tag)
	:m_x(x), m_y(y), m_width(width), m_height(height)
	, m_textureID(textureID)
	, m_tag(tag) {}

LoaderParams::LoaderParams(int x, int y, std::string textureID, std::string tag)
	:m_x(x), m_y(y), m_width(TextureManager::Instance()->get_SDL_Rect(textureID).w), m_height(TextureManager::Instance()->get_SDL_Rect(textureID).h)
	, m_textureID(textureID)
	, m_tag(tag) {}

int LoaderParams::getX() const
{
	return m_x;
}

int LoaderParams::getY() const
{
	return m_y;
}

int LoaderParams::getWidth() const
{
	return m_width;
}

int LoaderParams::getHeight() const
{
	return m_height;
}

std::string LoaderParams::getTextureID() const
{
	return m_textureID;
}

std::string LoaderParams::getTag() const
{
	return m_tag;
}
