#pragma once
#include<iostream>
#include<string>
#include"Button.h"
#include"ProductViewModel.h"

class ProductView : public Button{
public:
	ProductView(ProductData* _data, const std::unique_ptr<LoaderParams*>& pParams, Vector2D _textVec, Vector2D _TextVecAmount);
	ProductView(const ProductView& src);
	virtual void draw();
private:
	ProductViewModel* m_ProductViewModel;
	std::string m_strPrice;
	std::string m_strAmount;
	std::string m_strPriceID;
	std::string m_strAmountID;
	Vector2D m_TextVecPrice;
	Vector2D m_TextVecAmount;

};