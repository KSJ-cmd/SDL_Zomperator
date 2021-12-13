#pragma once
#include"Use.h"
#include"Take.h"
class Food : public IUse,public ITake {
public:
	Food(int amount);
	Food(const Food& src) = default;
	Food& operator=(const Food& rsh) = default;

	virtual bool Use();
	virtual void Take();
	virtual void Lose(int _val);
	int get() const;
	void set(int data);
private:
	int m_Data;
};