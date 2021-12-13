#include "ProductData.h"


int ProductData::m_use_Conut_wp=0;
int ProductData::m_use_Conut_fd=0;
int ProductData::m_use_Conut_md=0;
int ProductData::m_research1_Lv=0;
int ProductData::m_research2_Lv=0;
int ProductData::m_research3_Lv=0;
ProductData::ProductData(int price, PRODUCT_PRICE price_Ty,int _productAmount)
	:cnt_base_price(price),base_price(cnt_base_price),cur_price(base_price)
	,m_Type(price_Ty),m_productAmount(_productAmount)
{
	calcuPrice();
}

ProductData::ProductData(const ProductData& src)
	:cnt_base_price(src.cnt_base_price), base_price(cnt_base_price), cur_price(base_price)
	,m_Type(src.m_Type), m_productAmount(src.m_productAmount)
{
	calcuPrice();
}

void ProductData::setPrice(int _price)
{
	cur_price = _price;
}

void ProductData::setPrice_str(std::string _text)
{
	str_Price = _text;
}

void ProductData::calcuPrice(float _researchVal, float _abilityVal, float _eventVal)
{

	base_price = cnt_base_price * _researchVal;
	int use_count = 1;
	switch (m_Type)
	{
	case PRODUCT_PRICE::WP:
		use_count = m_use_Conut_wp;
		break;
	case PRODUCT_PRICE::FD:
		use_count = m_use_Conut_fd;
		break;
	case PRODUCT_PRICE::MD:
		use_count = m_use_Conut_md;
		break;
	case PRODUCT_PRICE::RESEARCH1:
		use_count = m_research1_Lv;
		break;
	case PRODUCT_PRICE::RESEARCH2:
		use_count = m_research2_Lv;
		break;
	case PRODUCT_PRICE::RESEARCH3:
		use_count = m_research3_Lv;
		break;
	default:
		break;
	}
	cur_price = (base_price + (use_count * 20)) * _abilityVal * _eventVal;
	std::cout << "cur price" << cur_price << std::endl;
}

void ProductData::Producing()
{
	std::cout << "Producing" << std::endl;
	switch (m_Type)
	{
	case PRODUCT_PRICE::WP:
		m_use_Conut_wp++;
		break;
	case PRODUCT_PRICE::FD:
		m_use_Conut_fd++;
		break;
	case PRODUCT_PRICE::MD:
		m_use_Conut_md++;
		break;
	default:
		break;
	}
	calcuPrice();
}

int ProductData::getPrice() const
{
	return cur_price;
}

int ProductData::getAmount() const
{
	return m_productAmount;
}

PRODUCT_PRICE ProductData::getType() const
{
	return m_Type;
}

std::string ProductData::getText_price() const
{
	return str_Price;
}
