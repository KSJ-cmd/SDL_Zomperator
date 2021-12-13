#pragma once
#include<list>
#include"Observer.h"


class Subject {
public:
	Subject();
	virtual ~Subject();
	virtual void Attach(IObserver* observer);
	virtual void Detach(IObserver* observer);
	virtual void Notify();
	virtual void Notify(int _val);
private:
	std::list<IObserver*> m_Observers;
};
