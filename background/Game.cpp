#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<vector>
#include<list>
#include<memory>
//#include"Nation.h"

#include"Game.h"
#include"GameObject.h"
#include"TextureManager.h"
#include"User.h"

int Game::angle = 0;
Game* Game::_instance = nullptr;

Game* Game::Instance()
{
	if (_instance == nullptr) {
		std::cout << "new Game" << std::endl;
		_instance = new Game("Game Class", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);;
	}
	return _instance;
}

Game::Game(const char* title, int xpos, int ypos, int width, int height, int flags)
	: m_pWindow(SDL_CreateWindow(title, xpos, ypos, width, height, flags))
	, m_pRenderer(SDL_CreateRenderer(m_pWindow, -1, 0))
	, m_bRunning(true)
	,m_Balls(3)
{
	
	m_Balls[0] =  new Ball("images/setup_spr_0.png", "setup", 0, 0, 132, 121,m_pRenderer);
	m_Balls[0]->SetMoveStrategy(new MoveXY);
	m_Balls[1] = new Ball("Assets/animate-alpha.png", "animate", 0, 0, 128, 82, m_pRenderer);
	m_Balls[1]->SetMoveStrategy(new MoveX);
	
	//SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		//TextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer);
		TextureManager::Instance()->load("images/ending_fuckzombie_bg_spr_0.png", "background", m_pRenderer);
		//TextureManager::Instance()->load("images/setup_spr_0.png", "setup", m_pRenderer);
		
		
		
	}
	
}
Game::~Game() {

}
//void Game::Start() {
//	for (GameObject* i : GameObject::g_start) {
//		i->Start();
//	}
//	GameObject::g_start.clear();
//	
//}
void Game::Update() {
	m_currentFrame = ((SDL_GetTicks() / 100) % 6);
	for (GameObject* i : GameObject::g_update) {
		i->Update();
	}
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	
	/*for (std::list<Image*> i : Image::g_Surfaces) {
		for (Image* image : i) {
			
			SDL_Texture* m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, image->GetSurface());
			SDL_RenderCopy(m_pRenderer, m_pTexture, image->Size(), image->Position());
			SDL_Delay(10);
			image->MovePos();
		}
	}*/
	
	TextureManager::Instance()->draw("background", 0, 0, 1600 ,900 , m_pRenderer);
	TextureManager::Instance()->drawAngle("animate", 0, 0, 128, 82,angle++, m_pRenderer);
	//TextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	TextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);
	TextureManager::Instance()->draw("setup", m_Balls[0]->GetRect()->x, m_Balls[0]->GetRect()->y, 132, 121, m_pRenderer);
	TextureManager::Instance()->draw("animate", m_Balls[1]->GetRect()->x, m_Balls[1]->GetRect()->y, 128, 82, m_pRenderer);
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			SDL_Rect tempRect = { 2*j,2*i + 300,2,2 };
			if (maps[i][j] == 1) {
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
				SDL_RenderFillRect(m_pRenderer, &tempRect);
			}
		}
	}
	
	SDL_RenderPresent(m_pRenderer);
}

bool Game::running() {
	return m_bRunning;
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
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

//void Game::ResetTexture()
//{
//	for (std::list<Image*> i : Image::g_Surfaces) {
//		std::cout << "list size: " << i.size() << std::endl;
//		for (Image* image : i) {
//			delete image;
//		}
//	}
//	Image::g_Surfaces.clear();
//
//	//Image::g_renderer.clear();
//}
