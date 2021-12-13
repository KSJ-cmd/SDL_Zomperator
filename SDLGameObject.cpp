#include<iostream>
#include"TextureManager.h"
#include"Game.h"
#include"SDLGameObject.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

SDLGameObject::SDLGameObject(const std::unique_ptr<LoaderParams*>& pParams)
    :GameObject(pParams)
    , m_position((float)(*pParams)->getX(), (float)(*pParams)->getY())
    , m_velocity(0, 0)
    , m_acceleration(0, 0)
    , m_Scale(1, 1)
    , isActive(true), isDestroy(false)
{
    m_width = (*pParams)->getWidth();
    m_height = (*pParams)->getHeight();
    m_textureID = (*pParams)->getTextureID();
    m_tag = (*pParams)->getTag();
    m_currentRow = 0;
    m_currentFrame = 0;
}
SDLGameObject::SDLGameObject(const std::unique_ptr<LoaderParams*>& pParams, Vector2D scale) :GameObject(pParams)
, m_position((float)(*pParams)->getX(), (float)(*pParams)->getY())
, m_velocity(0, 0)
, m_acceleration(0, 0)
, m_Scale(scale)
, isActive(true), isDestroy(false)
{
    m_width = (*pParams)->getWidth();
    m_height = (*pParams)->getHeight();
    m_textureID = (*pParams)->getTextureID();
    m_tag = (*pParams)->getTag();
    m_currentRow = 0;
    m_currentFrame = 0;
}
SDLGameObject::SDLGameObject(const SDLGameObject& src)
    :GameObject(src)
, m_position((float)src.m_position.getX(), (float)src.m_position.getY())
, m_velocity(src.m_velocity.getX(), src.m_velocity.getY())
, m_acceleration(src.m_acceleration.getX(), src.m_acceleration.getY())
, m_Scale(src.m_Scale)
, isActive(src.getActive()), isDestroy(false)
{
    m_width = src.m_width;
    m_height = src.m_height;
    m_textureID = src.m_textureID;
    m_tag = src.m_tag;
    m_currentRow = src.m_currentRow;
    m_currentFrame = src.m_currentFrame;
}

void SDLGameObject::update() {

    m_velocity += m_acceleration;
    m_position += m_velocity;
}
void SDLGameObject::draw(){
    TextureManager::Instance()->drawQuery(m_textureID, (int)m_position.getX(), (int)m_position.getY(),m_Scale.getX(),m_Scale.getY(), Game::Instance()->getRenderer());
}


void SDLGameObject::move(SDLGameObject& wall)
{
    if ((m_position.getX() < 0) || (m_position.getX() + m_width > SCREEN_WIDTH) || check_collision(*this, wall)) {
        m_position.setX(m_position.getX() - m_velocity.getX());
        m_velocity.setX(0);
    }
    if ((m_position.getY() < 0) || (m_position.getY() + m_width > SCREEN_HEIGHT) || check_collision(*this, wall)) {
        m_position.setY(m_position.getY() - m_velocity.getY());
        m_velocity.setY(0);
        
    }
}

void SDLGameObject::setScale(Vector2D vector)
{
    m_Scale = vector;
}

std::string SDLGameObject::getTag() const
{
    return m_tag;
}

bool SDLGameObject::getActive() const
{
    return isActive;
}

void SDLGameObject::Active()
{
    isActive = true;
}

void SDLGameObject::InActive()
{
    isActive = false;
}

bool SDLGameObject::getDestroy() const
{
    return isDestroy;
}

void SDLGameObject::Destroy()
{
    isDestroy = true;
}

bool SDLGameObject::check_collision(const SDLGameObject& A, const SDLGameObject& B)
{
    if (check_collision_X(A, B) && check_collision_Y(A, B))
        return true;
    else
        return false;
}

bool SDLGameObject::check_collision_X(const SDLGameObject& A, const SDLGameObject& B)
{
    int leftA, leftB;
    int rightA, rightB;

    leftA = A.m_position.getX();
    rightA = A.m_position.getX() + A.m_width;

    leftB = B.m_position.getX();
    rightB = B.m_position.getX() + B.m_width;

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    return true;
}

bool SDLGameObject::check_collision_Y(const SDLGameObject& A, const SDLGameObject& B)
{
    int topA, topB;
    int bottomA, bottomB;

    topA = A.m_position.getY();
    bottomA = A.m_position.getY() + A.m_height;

    topB = B.m_position.getY();
    bottomB = B.m_position.getY() + B.m_height;

    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }


    return true;
}

bool SDLGameObject::check_collision_camera()
{
    if ((m_position.getX() < 0) || (m_position.getX() + m_width > SCREEN_WIDTH)) {
        return true;
    }
    if ((m_position.getY() < 0) || (m_position.getY() + m_width > SCREEN_HEIGHT)) {
        return true;
    }
    return false;
}

bool SDLGameObject::check_collision_mouse(const Vector2D& mousePosition)
{
    int targetX = m_position.getX();
    int targetY = m_position.getY();
    int targetW = m_position.getX() + (m_width * m_Scale.getX());
    int targetH = m_position.getY() + (m_height * m_Scale.getY());

    if ((targetX <= mousePosition.getX() && mousePosition.getX() <= targetW)
        &&
        (targetY <= mousePosition.getY() && mousePosition.getY() <= targetH)) {
        std::cout << "mouse collison true" << std::endl;
        return true;
    }
    else {
        std::cout << "mouse collison fail" << std::endl;
        return false;
    }
}
