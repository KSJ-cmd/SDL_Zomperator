#include"Cmd_Turn.h"
#include"Nation.h"
#include"NationHandler.h"
#include"SubjectNation.h"
#include"Data.h"
#include"Fade.h"

Cmd_Turn::Cmd_Turn(Button* _button)
	:m_Button(_button)
{
}

Cmd_Turn::~Cmd_Turn()
{
}

void Cmd_Turn::execute()
{
	std::cout << "Turn_over" << std::endl;
	SubjectNation::Instance()->Notify(10);
	SubjectNation::Instance()->Notify();
	Data::Instance()->TakeMoney();
	Data::Instance()->resetLimitNum();
	Data::Instance()->TurnEnd();
	std::unique_ptr<LoaderParams*> p_loader_Fade = std::make_unique<LoaderParams*>(new LoaderParams(0, 0,1600,900, "fade_black_0", "fade_black_0"));
	Fade* fade = new Fade(p_loader_Fade);
	Game::Instance()->render();
	int numAlive = 0;
	for (auto nation : NationHandler::getNations()) {
		if (nation->getAlive()==false) {
			numAlive++;
		}
	}
	std::cout << numAlive << std::endl;
	if (numAlive == 8) {
		Game::Instance()->quit();
		return;
	}
		SDL_Delay(300);
	for (int i = 8; i < fade->getAlpha(); ) {
		fade->ApplyAlpha(i);
		Game::Instance()->render();
	}
	delete fade;

}
