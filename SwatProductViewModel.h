#pragma once
#include<iostream>
#include<vector>
#include"SwatProductData.h"
class SwatProductViewModel{
public:
	SwatProductViewModel();
	SwatProductViewModel(const SwatProductViewModel& src);
	~SwatProductViewModel();

	void DataInsert(SwatProductData* _Data);
	std::vector< SwatProductData*> get() const;
	SwatProductData* get(INVESTMENT _type) const;

	bool Invest(INVESTMENT _Type);
private:
	std::vector< SwatProductData*> m_Datas;
};

