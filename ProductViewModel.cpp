#include "ProductViewModel.h"

ProductViewModel::ProductViewModel(ProductData* _data)
	:m_data(_data)
{
}

ProductViewModel::ProductViewModel(const ProductViewModel& src)
	:m_data(new ProductData(*src.m_data))
{

}

ProductViewModel::~ProductViewModel()
{
	delete m_data;
}

int ProductViewModel::getPrice() const
{
	return m_data->getPrice();
}

int ProductViewModel::getAmount() const
{
	return m_data->getAmount();
}

PRODUCT_PRICE ProductViewModel::getType() const
{
	return m_data->getType();
}


