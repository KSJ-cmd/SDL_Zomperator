#pragma once
#include"Use.h"
#include"Take.h"
class Weapon :public IUse ,public ITake{
public:
	Weapon(int amount);
	Weapon(const Weapon& src) = default;
	Weapon& operator=(const Weapon& rsh) = default;

	virtual bool Use();
	virtual void Take();
	virtual void Lose(int _val);

	int get() const;
	void set(int data);
private:
	int m_Data;
};