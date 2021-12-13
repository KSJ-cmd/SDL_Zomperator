#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<vector>
#include<list>
#include<memory>

#include"Game.h"
#include"TextureManager.h"
#include"SDLGameObject.h"
#include"InputHandler.h"
#include"PlayroomHandler.h"
#include"Playroom.h"
Game* Game::s_pInstance = 0;

Game* Game::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new Game();
	}
	return s_pInstance;
}

Game::Game()
{
	delete s_pInstance;
}
Game::~Game() {
	std::cout << "Game end" << std::endl;
}
bool Game::Init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) {
			TTF_Init();
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			m_pFont = TTF_OpenFont("font/BMDOHYEON_ttf.ttf", 30);
			TextureManager::Instance()->Texture_Init();

			std::unique_ptr<Scene*> pU = std::make_unique<Scene*>(new Playroom("main"));
			PlayroomHandler::Instance()->set(std::move(pU));
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	m_bRunning = true;
	return true;
}

void Game::Update() {
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	if (PlayroomHandler::Instance()->get() != nullptr)
		PlayroomHandler::Instance()->get()->update();
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	if (PlayroomHandler::Instance()->get() != nullptr)
		PlayroomHandler::Instance()->get()->draw();
	
	SDL_RenderPresent(m_pRenderer);
}

bool Game::running() {
	return m_bRunning;
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
}

void Game::clean() {
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

SDL_Renderer* Game::getRenderer() const
{
	return m_pRenderer;
}

TTF_Font* Game::getFont() const
{
	return m_pFont;
}


