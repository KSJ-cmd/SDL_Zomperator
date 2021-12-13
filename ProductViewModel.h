#pragma once
#include"ProductData.h"

class ProductViewModel {
public:
	ProductViewModel(ProductData* _data);
	ProductViewModel(const ProductViewModel& src);
	~ProductViewModel();
	int getPrice() const;
	int getAmount() const;
	PRODUCT_PRICE getType() const;
private:
	ProductData* m_data;
};