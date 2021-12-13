#include"Subject.h"
#include<iostream>
Subject::Subject() {

}
Subject::~Subject()
{
	m_Observers.clear();
}

void Subject::Attach(IObserver* observer)
{
	m_Observers.push_back(observer);
}

void Subject::Detach(IObserver* observer)
{
	m_Observers.remove(observer);
}


void Subject::Notify()
{
	std::cout << "Notify" << std::endl;
	for (auto ob : m_Observers) {
		ob->Observer_update();
	}
}

void Subject::Notify(int _val)
{
	std::cout << "Notify_int" << std::endl;
	for (auto ob : m_Observers) {
		ob->Observer_update(_val);
	}
}



