#pragma once
#include"Use.h"
#include"Take.h"
class Medicine:public IUse,public ITake {
public:
	Medicine(int amount);
	Medicine(const Medicine& src) = default;
	Medicine& operator=(const Medicine& rsh) = default;

	virtual bool Use();
	virtual void Take();
	virtual void Lose(int _val);

	int get() const;
	void set(int data);
private:
	int m_Data;
};