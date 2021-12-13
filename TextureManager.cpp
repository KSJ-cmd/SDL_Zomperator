#include"Game.h"
#include"TextureManager.h"
#include<SDL.h>
#include<SDL_image.h>
//#include<SDL_ttf.h>
#include<utility>

TextureManager* TextureManager::s_pInstance = 0;

TextureManager* TextureManager::Instance()
{
	if (s_pInstance == 0) {
		s_pInstance = new TextureManager();
	}
	return s_pInstance;
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

		if (pTempSurface == NULL) {
			printf("%s\n", IMG_GetError());
		return false;
		}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (pTexture != 0) {
		if (m_textureMap[id] != nullptr) {
			SDL_DestroyTexture(m_textureMap[id]);
		}
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}

bool TextureManager::loadText(std::string text, std::string id, SDL_Renderer* pRenderer, TTF_Font* pFont, SDL_Color textColor = {0,0,0})
{
	SDL_Surface* pTempSurface = TTF_RenderText_Solid(pFont,text.c_str(),textColor);

	if (pTempSurface == NULL) {
		printf("%s\n", TTF_GetError());
		std::cout << "error ttf" << std::endl;
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (pTexture != 0) {
		if (m_textureMap[id] != nullptr) {
			SDL_DestroyTexture(m_textureMap[id]);
		}
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawQuery(std::string id, int x, int y, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &srcRect.w, &srcRect.h);

	srcRect.x = srcRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawQueryPivot(std::string id, int x, int y, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &srcRect.w, &srcRect.h);

	srcRect.x = srcRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = x-(srcRect.w/2);
	destRect.y = y-(srcRect.h/2);

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawQuery(std::string id, int x, int y, float xScale, float yScale, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &srcRect.w, &srcRect.h);

	srcRect.x = srcRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	destRect.x = x;
	destRect.y = y;
	destRect.w *= xScale;
	destRect.h *= yScale;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,  int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);

}
void TextureManager::drawAngle(std::string id, int x, int y, int width, int height, int angle, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, angle, 0, flip);

}

void TextureManager::BlendAlpha(Uint8 alpha, std::string id)
{

	SDL_SetTextureAlphaMod(m_textureMap[id], alpha);

	
}

void TextureManager::Texture_Init()
{
	//배경
	load("images/main_play_place_0.png", "main_play_place_0", Game::Instance()->getRenderer());//o
	//load("awaken_apr_0.png", "awaken_apr_0", Game::Instance()->getRenderer());
	
	//턴 아이콘
	load("images/Turn_over_0.png", "Turn_over_0", Game::Instance()->getRenderer()); //o
	load("images/fade_black_0.png", "fade_black_0", Game::Instance()->getRenderer());
	
	

	//기본 버튼
	load("images/sup_cancel_0.png", "sup_cancel_0", Game::Instance()->getRenderer());
	
	

	
	//이벤트
	load("images/event_bg_spr_0.png", "event_bg_spr_0", Game::Instance()->getRenderer());
	load("images/event_tab_spr_0.png", "event_tab_spr_0", Game::Instance()->getRenderer());
	
	
	
	load("images/event_money_spr_0.png", "event_money_spr_0", Game::Instance()->getRenderer());
	
	load("images/event_fd_spr_0.png", "event_fd_spr_0", Game::Instance()->getRenderer());
	load("images/event_fd_ext_spr_0.png", "event_fd_ext_spr_0", Game::Instance()->getRenderer());
	
	load("images/event_md_spr_0.png", "event_md_spr_0", Game::Instance()->getRenderer());
	load("images/event_md_ext_spr_0.png", "event_md_ext_spr_0", Game::Instance()->getRenderer());
	
	load("images/event_res_spr_0.png", "event_res_spr_0", Game::Instance()->getRenderer());
	load("images/event_res_ext_spr_0.png", "event_res_ext_spr_0", Game::Instance()->getRenderer());

	load("images/event_sup_spr_0.png", "event_sup_spr_0", Game::Instance()->getRenderer());
	load("images/event_sup_ext_spr_0.png", "event_sup_ext_spr_0", Game::Instance()->getRenderer());
	
	load("images/event_wp_spr_0.png", "event_wp_spr_0", Game::Instance()->getRenderer());
	load("images/event_wp_ext_spr_0.png", "event_wp_ext_spr_0", Game::Instance()->getRenderer());

	

	
	//자원
	load("images/sup_product_res_spr_0.png", "sup_product_res_spr_0", Game::Instance()->getRenderer());
	load("images/res_tab_spr_0.png", "res_tab_spr_0", Game::Instance()->getRenderer());
	load("images/base_res_spr_0.png", "base_res_spr_0", Game::Instance()->getRenderer());
	load("images/sup_res_spr_0.png", "sup_res_spr_0", Game::Instance()->getRenderer());
	load("images/res_start_spr_0.png", "res_start_spr_0", Game::Instance()->getRenderer());
	load("images/res_inf_spr_0.png", "res_inf_spr_0", Game::Instance()->getRenderer());
	load("images/res_tab_ext_spr_0.png", "res_tab_ext_spr_0", Game::Instance()->getRenderer());
	load("images/res_BG_spr_0.png", "res_BG_spr_0", Game::Instance()->getRenderer());

	//타격대
	load("images/swat_attack_tab_spr_0.png", "swat_attack_tab_spr_0", Game::Instance()->getRenderer());
	load("images/swat_manage_bg_spr_0.png", "swat_manage_bg_spr_0", Game::Instance()->getRenderer());
	load("images/swat_put_cancel_spr_0.png", "swat_put_cancel_spr_0", Game::Instance()->getRenderer());
	load("images/swat_tab_spr_0.png", "swat_tab_spr_0", Game::Instance()->getRenderer());
	load("images/swat_funding_spr_0.png", "swat_funding_spr_0", Game::Instance()->getRenderer());
	
	

	//엔딩 이미지
	load("images/ending_ali_bg_spr_0.png", "ending_ali_bg_spr_0", Game::Instance()->getRenderer());
	load("images/ending_ali_inf_spr_0.png", "ending_ali_inf_spr_0", Game::Instance()->getRenderer());
	
	load("images/ending_des_bg_spr_0.png", "ending_des_bg_spr_0", Game::Instance()->getRenderer());
	load("images/ending_des_inf_spr_0.png", "ending_des_inf_spr_0", Game::Instance()->getRenderer());
	
	load("images/ending_fuckzombie_bg_spr_0.png", "ending_fuckzombie_bg_spr_0", Game::Instance()->getRenderer());
	load("images/ending_fuckzombie_inf_spr_0.png", "ending_fuckzombie_inf_spr_0", Game::Instance()->getRenderer());


	load("images/message_bor_0.png", "message_bor_0", Game::Instance()->getRenderer());
	
	//작업중
	//메인 버튼 아이콘
	load("images/sup_manage_0.png", "sup_manage_0", Game::Instance()->getRenderer()); // 자원관리
	load("images/swat_management_spr_0.png", "swat_management_spr_0", Game::Instance()->getRenderer()); // 타격대 관리
	load("images/swat_put_icon_spr_0.png", "swat_put_icon_spr_0", Game::Instance()->getRenderer()); //타격대투입
	load("images/inf_icon_spr_0.png", "inf_icon_spr_0", Game::Instance()->getRenderer()); // 운영정보
	load("images/event_icon_spr_0.png", "event_icon_spr_0", Game::Instance()->getRenderer()); //이벤트 정보
	//자원 투입아이콘
	load("images/sup_fd_spr_0.png", "sup_fd_spr_0", Game::Instance()->getRenderer());
	load("images/sup_md_spr_0.png", "sup_md_spr_0", Game::Instance()->getRenderer());
	load("images/sup_wp_spr_0.png", "sup_wp_spr_0", Game::Instance()->getRenderer());

	//국가별 아이콘
	load("images/Alive_place_0.png", "Alive_place_0", Game::Instance()->getRenderer());
	load("images/Destroy_place_0.png", "Destroy_place_0", Game::Instance()->getRenderer());
	load("images/fd_lack_0.png", "fd_lack_0", Game::Instance()->getRenderer());
	load("images/md_lack_0.png", "md_lack_0", Game::Instance()->getRenderer());
	load("images/wp_lack_0.png", "wp_lack_0", Game::Instance()->getRenderer());
	//운영 정보
	load("images/inf_bg_spr_0.png", "inf_bg_spr_0", Game::Instance()->getRenderer());

	//버튼 클릭중
	load("images/sup_progressing_0.png", "sup_progressing_0", Game::Instance()->getRenderer()); //yet
	load("images/wp_progressing_0.png", "wp_progressing_0", Game::Instance()->getRenderer());
	load("images/md_progressing_0.png", "md_progressing_0", Game::Instance()->getRenderer());
	load("images/fd_progressing_0.png", "fd_progressing_0", Game::Instance()->getRenderer());

	//생산
	load("images/sup_product_BG_0.png", "sup_product_BG_0", Game::Instance()->getRenderer());
	load("images/sup_production_0.png", "sup_production_0", Game::Instance()->getRenderer());


	load("images/sup_product_tab_spr_0.png", "sup_product_tab_spr_0", Game::Instance()->getRenderer());
	load("images/sup_product_ext_spr_0.png", "sup_product_ext_spr_0", Game::Instance()->getRenderer());

	//취소버튼
	load("images/X_but_0.png", "X_but_0", Game::Instance()->getRenderer());
}
	

SDL_Rect& TextureManager::get_SDL_Rect(std::string id) 
{
	SDL_Rect srcRect;
	SDL_QueryTexture(m_textureMap[id], NULL, NULL, &srcRect.w, &srcRect.h);

	return srcRect;
}

