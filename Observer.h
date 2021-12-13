#pragma once

class IObserver {
public:
	virtual ~IObserver(){}
	virtual void Observer_update() = 0;
	virtual void Observer_update(int _val) = 0;

};

class ResourceObserver : public IObserver {
public:
	virtual ~ResourceObserver(){}
	virtual void Observer_update() = 0;
	virtual void Observer_update(int _val) = 0;
};

