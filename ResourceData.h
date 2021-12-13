#pragma once
#include"WP.h"
#include"FD.h"
#include"MD.h"
class ResourceData {
public:
	ResourceData(Weapon* weapon, Medicine* medicine, Food* food);
	~ResourceData();
	ResourceData& operator=(const ResourceData& rsh);

	void takeWP(int _amount);
	void takeFD(int _amount);
	void takeMD(int _amount);


	Weapon* getWP() const;
	Food* getFD() const;
	Medicine* getMD() const;
private:
	ResourceData(const ResourceData& src);

	Weapon* m_Weapon;
	Food* m_Food;
	Medicine* m_Medicine;
};