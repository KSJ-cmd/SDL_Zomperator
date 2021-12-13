#pragma once
#include"Use.h"
#include"Take.h"
class Hp : public IUse, public ITake {
public:
	Hp(int amount);
	Hp(const Hp& src) = default;
	Hp& operator=(const Hp& rsh) = default;

	virtual bool Use();
	virtual void Take();
	virtual void Lose(int _val);

	int get() const;
	void set(int data);
private:
	int m_Data;
};