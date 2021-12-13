#include"Cmd_Investment_Swat.h"
#include"Data.h"
#include"PopupWin.h"
#include"Cmd_Xbutton.h"
#include<random>
Cmd_Investment_Swat::Cmd_Investment_Swat(Nation* _Nation)
	:m_Nation(_Nation)
{

}
Cmd_Investment_Swat::~Cmd_Investment_Swat()
{
}

void Cmd_Investment_Swat::execute()
{

	if (Data::Instance()->CheckLimitNum() == true && Data::Instance()->getSwatSuccessRate() > 1 && m_Nation->getAlive() == false) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, 100);
		int rate = dis(gen);

		std::cout << "·£´ýÈ®·ü : " << rate << std::endl;
		std::cout << "¼º°øÈ®·ü : " << Data::Instance()->getSwatSuccessRate() << std::endl;
		if (rate <= Data::Instance()->getSwatSuccessRate()) {
			//¼º°ø
			std::cout << "swat ¼º°ø" << std::endl;
			m_Nation->Recovery();
			std::unique_ptr<LoaderParams*> p_loader_popup = std::make_unique<LoaderParams*>(new LoaderParams(447, 239,1600,900, "message_bor_0", "message_bor_0"));
			PopupWin* popupWin = new PopupWin(p_loader_popup,"Swat Success");
			popupWin->setCommand(new Cmd_Xbutton(popupWin));
			popupWin->setScale(Vector2D(0.8, 0.8));
		}
		else {
			//½ÇÆÐ
			std::cout << "swat ½ÇÆÐ" << std::endl;
			std::unique_ptr<LoaderParams*> p_loader_popup = std::make_unique<LoaderParams*>(new LoaderParams(447, 239, 1600, 900, "message_bor_0", "message_bor_0"));
			PopupWin* popupWin = new PopupWin(p_loader_popup, "Swat Fail");
			popupWin->setCommand(new Cmd_Xbutton(popupWin));
			popupWin->setScale(Vector2D(0.8, 0.8));
		}
	}
	else {
		return;
	}
}
