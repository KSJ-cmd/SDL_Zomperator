#pragma once
#include<iostream>
#include<string>
#include"Button.h"
#include"SwatProductData.h"
#include"SwatProductViewModel.h"

class SwatProductView : public Button{
public:
	SwatProductView(const std::unique_ptr<LoaderParams*>& pParams
		, SwatProductViewModel* _SwatProductViewModel, INVESTMENT _Type);
	//SwatProductView(const SwatProductView& src):Button(nullptr){}
	~SwatProductView();
	void DataInsert(SwatProductData* _Data);
	virtual void draw();

private:
	SwatProductViewModel* m_SwatProductViewModel;
	INVESTMENT m_Type;
	std::string m_AmountID;
}; 