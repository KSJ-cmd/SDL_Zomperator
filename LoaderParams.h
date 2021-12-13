#ifndef __LOADERPARAMS_H__
#define __LOADERPARAMS_H__

#include<iostream>
class LoaderParams {
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID, std::string tag);
    LoaderParams(int x, int y, std::string textureID, std::string tag);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    std::string getTextureID() const;
    std::string getTag() const;
private:
    int m_x = 0;
    int m_y = 0;
    int m_width = 0;
    int m_height = 0;

    std::string m_textureID = "";
    std::string m_tag = "";
};
#endif 