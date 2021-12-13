#pragma once
class Scene {
public:
	virtual ~Scene() {}
	virtual void update()=0;
	virtual void draw()=0;
private:
	//Scene(const Scene& src);
	//Scene& operator= (const Scene& rsh) {}
};