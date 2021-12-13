#pragma once
#include<iostream>
#include"Observer.h"
enum class PRODUCT_PRICE :int
{
	WP = 0, FD, MD, RESEARCH1, RESEARCH2, RESEARCH3,
};
class ProductData {
public:
	ProductData(int price, PRODUCT_PRICE price_Ty, int _productAmount = 1);
	ProductData(const ProductData& src);
	void setPrice(int _price);
	void setPrice_str(std::string _text);

	void calcuPrice(float _researchVal = 1, float _abilityVal = 1, float _eventVal = 1);
	void Producing();
	int getPrice() const;
	int getAmount() const;
	PRODUCT_PRICE getType() const;
	std::string getText_price() const;

private:
	const int cnt_base_price;
	int base_price;
	int cur_price;
	int m_productAmount;
	PRODUCT_PRICE m_Type;
	std::string str_Price;
	static int m_use_Conut_wp;
	static int m_use_Conut_fd;
	static int m_use_Conut_md;
	static int m_research1_Lv;
	static int m_research2_Lv;
	static int m_research3_Lv;
};


