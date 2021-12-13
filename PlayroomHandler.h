#pragma once
#include<memory>
#include<vector>
#include"Playroom.h"
#include"Scene.h"

class PlayroomHandler{
public:
	static PlayroomHandler* Instance() {
		if (_sInstance == 0) {
			_sInstance = std::make_shared<PlayroomHandler*>(new PlayroomHandler());
		}
		return (*_sInstance);
	}
	PlayroomHandler();
	virtual void update();
	virtual void draw() {}
	virtual void clean() {}

	void set(std::unique_ptr<Scene*> uScene);

	Scene* get() const;
	std::vector<Scene*>& getScenes();
	const std::vector<Scene*>& getScenes() const;
private:
	static std::shared_ptr<PlayroomHandler*> _sInstance;
	std::vector<Scene*> _mScenes;
	std::unique_ptr<Scene*> _mUscene;
};