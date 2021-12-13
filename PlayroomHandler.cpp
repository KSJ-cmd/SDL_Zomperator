#include"PlayroomHandler.h"

std::shared_ptr<PlayroomHandler*> PlayroomHandler::_sInstance = nullptr;

PlayroomHandler::PlayroomHandler()
{
	//_mUscene = std::make_unique<Scene*>(new Playroom("main"));
}

void PlayroomHandler::update()
{
	(*_mUscene)->update();
}

void PlayroomHandler::set(std::unique_ptr<Scene*> uScene)
{
	if (_mUscene != nullptr) {
		delete *_mUscene;
	}
	_mUscene = std::move(uScene);
}
Scene* PlayroomHandler::get() const
{
	return (*_mUscene);
}

std::vector<Scene*>& PlayroomHandler::getScenes()
{
	return _mScenes;
}
const std::vector<Scene*>& PlayroomHandler::getScenes() const
{
	return _mScenes;
}
