#include"Playroom.h"
#include"NationHandler.h"

#include"Nation.h"

#include"SubjectNation.h"
#include<algorithm>

std::vector<Nation*> NationHandler::m_Nations;
NationHandler::NationHandler()
{
	std::unique_ptr<LoaderParams*> _GL = std::make_unique<LoaderParams*>(new LoaderParams(714, 247, "Alive_place_0", "GL"));
	Nation* newGL = new Nation(_GL, Vector2D(140, 260), Vector2D(210, 25));
	m_Nations.push_back(newGL);
	Playroom::getGameObjects().push_back(newGL);
	SubjectNation::Instance()->Attach(newGL);

	std::unique_ptr<LoaderParams*> _NA = std::make_unique<LoaderParams*>(new LoaderParams(516, 294, "Alive_place_0", "NA"));
	Nation* newNA = new Nation(_NA, Vector2D(140, 357), Vector2D(210, 25));
	m_Nations.push_back(newNA);
	Playroom::getGameObjects().push_back(newNA);
	SubjectNation::Instance()->Attach(newNA);

	std::unique_ptr<LoaderParams*> _MA = std::make_unique<LoaderParams*>(new LoaderParams(593, 360, "Alive_place_0", "MA"));
	Nation* newMA = new Nation(_MA, Vector2D(140, 454), Vector2D(210, 25));
	newMA->getHp()->set(0);
	newMA->Dead();

	m_Nations.push_back(newMA);
	Playroom::getGameObjects().push_back(newMA);
	SubjectNation::Instance()->Attach(newMA);

	std::unique_ptr<LoaderParams*> _SA = std::make_unique<LoaderParams*>(new LoaderParams(668, 495, "Alive_place_0", "SA"));
	Nation* newSA = new Nation(_SA, Vector2D(140, 551), Vector2D(210, 25));
	m_Nations.push_back(newSA);
	Playroom::getGameObjects().push_back(newSA);
	SubjectNation::Instance()->Attach(newSA);

	std::unique_ptr<LoaderParams*> _UR = std::make_unique<LoaderParams*>(new LoaderParams(860, 329, "Alive_place_0", "UR"));
	Nation* newUR = new Nation(_UR, Vector2D(1250, 260), Vector2D(210, 25));
	m_Nations.push_back(newUR);
	Playroom::getGameObjects().push_back(newUR);
	SubjectNation::Instance()->Attach(newUR);

	std::unique_ptr<LoaderParams*> _AF = std::make_unique<LoaderParams*>(new LoaderParams(853, 442, "Alive_place_0", "AF"));
	Nation* newAF = new Nation(_AF, Vector2D(1250, 357), Vector2D(210, 25));
	m_Nations.push_back(newAF);
	Playroom::getGameObjects().push_back(newAF);
	SubjectNation::Instance()->Attach(newAF);

	std::unique_ptr<LoaderParams*> _OS = std::make_unique<LoaderParams*>(new LoaderParams(1098, 514, "Alive_place_0", "OS"));
	Nation* newOS = new Nation(_OS, Vector2D(1250, 454), Vector2D(210, 25));
	m_Nations.push_back(newOS);
	Playroom::getGameObjects().push_back(newOS);
	SubjectNation::Instance()->Attach(newOS);

	std::unique_ptr<LoaderParams*> _AS = std::make_unique<LoaderParams*>(new LoaderParams(1011, 329, "Alive_place_0", "AS"));
	Nation* newAS = new Nation(_AS, Vector2D(1250, 551), Vector2D(210, 25));
	m_Nations.push_back(newAS);
	Playroom::getGameObjects().push_back(newAS);
	SubjectNation::Instance()->Attach(newAS);

}

std::vector<Nation*>& NationHandler::getNations()
{
	return m_Nations;
}
