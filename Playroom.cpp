#include<memory>
#include"Playroom.h"
#include"PlayroomHandler.h"
#include"TextureManager.h"
#include"InputHandler.h"
#include"SDLGameObject.h"


   
std::vector<SDLGameObject*> Playroom::m_bgObjects;
std::vector<SDLGameObject*> Playroom::m_gameObjects;
std::list<Button*> Playroom::m_ButtonObjects;
std::list<Window*> Playroom::m_WindowObjects;

Playroom::Playroom(std::string name)
    :_name(name),isClick(false)
{
    std::unique_ptr<LoaderParams*> pL_bg = std::make_unique<LoaderParams*>(new LoaderParams(0, 0, "main_play_place_0", "background"));
    m_bgObjects.push_back(new SDLGameObject(pL_bg));

    _buttonHandler = new ButtonHandler();
    _nationHandler = new NationHandler();
    _dataControl = DataControl::Instance();
    
    PlayroomHandler::Instance()->getScenes().push_back(std::move(this));
}
Playroom::~Playroom()
{
    delete _buttonHandler;
    delete _nationHandler;
    delete _dataControl;
}
void Playroom::update() {
    handleInput();
    
    for (std::vector<SDLGameObject*>::iterator iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++) {
        (*iter)->update();
    }
}

void Playroom::draw()
{
    for (std::vector<SDLGameObject*>::iterator iter = m_bgObjects.begin(); iter != m_bgObjects.end(); iter++) {
        (*iter)->draw();
    }
    for (std::vector<SDLGameObject*>::iterator iter = m_gameObjects.begin(); iter != m_gameObjects.end(); iter++) {
        (*iter)->draw();
    }
    _dataControl->Draw();
    for (std::list<Button*>::iterator iter = m_ButtonObjects.begin(); iter != m_ButtonObjects.end(); iter++) {
        (*iter)->draw();
    }
    for (std::list<Window*>::iterator iter = m_WindowObjects.begin(); iter != m_WindowObjects.end(); iter++) {
        (*iter)->draw();
    }
}

void Playroom::handleInput()
{
    if (TheInputHandler::Instance()->getMouseButtonState(0) && isClick == false) {
        std::cout << "ButtonDown" << std::endl;
        isClick = true;

        ButtonClickCheck();
    }
    if (!TheInputHandler::Instance()->getMouseButtonState(0) && isClick == true) {
        std::cout << "ButtonUp" << std::endl;
        isClick = false;

    }
}

void Playroom::ButtonClickCheck() {
    std::list<Button*>::reverse_iterator iter;
    for (iter = m_ButtonObjects.rbegin(); iter != m_ButtonObjects.rend(); iter++) {
        Vector2D& mousePosition = (*TheInputHandler::Instance()->getMousePosition());
        if ((*iter)->check_collision_mouse(mousePosition) == true) {
            if ((*iter)->getActive() == true)
                (*iter)->OnClick();
            break;
        }
    }
}

DataControl& Playroom::getData() const
{
    return *_dataControl;
}


std::vector<SDLGameObject*>& Playroom::getGameObjects()
{
    return m_gameObjects;
}

std::list<Button*>& Playroom::getButtons()
{
    return m_ButtonObjects;
}

std::list<Window*>& Playroom::getWindows()
{
    return m_WindowObjects;
}

