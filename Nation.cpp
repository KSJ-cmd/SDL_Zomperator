#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"Nation.h"
#include"PlayroomHandler.h"
#include"TextureManager.h"
#include"Game.h"


const int MAX = 100;
const int MIN = 0;

Nation::Nation(const std::unique_ptr<LoaderParams*>& pParams, const Vector2D& position, const Vector2D& area)
	:SDLGameObject(pParams)
	, m_Hp(new Hp(MAX)), m_Wp(new Weapon(MAX)), m_Md(new Medicine(MAX)), m_Fd(new Food(MAX)), isAlive(true)
	, m_supButton(new Button(pParams))
	, m_Hpbar(new HpBar(position, area, this))
	, m_iconPosition(position)
{
	m_supButton->InActive();
}
Nation::~Nation() {
	delete m_supButton;
	delete m_Hpbar;
	delete m_Hp;
	delete m_Wp;
	delete m_Md;
	delete m_Fd;
}
void Nation::update() {
}

void Nation::draw() {
	SDLGameObject::draw();
	if (m_Wp->get() <= 60)
		TextureManager::Instance()->drawQuery("wp_lack_0", m_iconPosition.getX(), m_iconPosition.getY() + 28, Game::Instance()->getRenderer());
	if (m_Fd->get() <= 60)
		TextureManager::Instance()->drawQuery("fd_lack_0", m_iconPosition.getX() + 35, m_iconPosition.getY() + 28, Game::Instance()->getRenderer());
	if (m_Md->get() <= 60)
		TextureManager::Instance()->drawQuery("md_lack_0", m_iconPosition.getX() + 70, m_iconPosition.getY() + 28, Game::Instance()->getRenderer());
	m_Hpbar->draw();
}



Hp* Nation::getHp() const { 
	return m_Hp; 
}
Weapon* Nation::getWp() const {
	return m_Wp; 
}
Medicine* Nation::getMd() const {
	return m_Md; 
}
Food* Nation::getFd() const { 
	return m_Fd; 
}

Button* Nation::getButton() const
{
	return m_supButton;
}

bool Nation::getAlive() const
{
	return isAlive;
}

void Nation::Recovery()
{
	Alive();
	m_Hp->set(100);
	m_Wp->set(100);
	m_Fd->set(100);
	m_Md->set(100);
}

void Nation::Alive()
{
	isAlive = true;
	m_supButton->TransTexture(BUTTONSTATE::IDLE);
}

void Nation::Dead()
{
	std::cout<<"Nation Dead" << std::endl;
	isAlive = false;
	m_supButton->SetProcessingTexture("Destroy_place_0");
	m_supButton->TransTexture(BUTTONSTATE::PROCESS);
	m_Hp->set(0);
	m_Wp->set(0);
	m_Fd->set(0);
	m_Md->set(0);
}

void Nation::Ability()
{
}

void Nation::setCommand(ICommand* _command)
{
	m_supButton->setCommand(_command);
}

void Nation::Observer_update()
{
	if (m_Hp->get() <= 0) {
		Dead();
	}
}

void Nation::Observer_update(int _val)
{
	m_Hp->Lose(_val);
	m_Wp->Lose(_val/2);
	m_Fd->Lose(_val/2);
	m_Md->Lose(_val/2);
}



