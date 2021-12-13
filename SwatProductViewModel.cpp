#include "SwatProductViewModel.h"

SwatProductViewModel::SwatProductViewModel()
{
}

SwatProductViewModel::SwatProductViewModel(const SwatProductViewModel& src)
{
}

SwatProductViewModel::~SwatProductViewModel()
{
	for (SwatProductData* i : m_Datas) {
		delete i;
	}
	m_Datas.clear();
	m_Datas.shrink_to_fit();
}

void SwatProductViewModel::DataInsert(SwatProductData* _Data)
{
	m_Datas.emplace_back(_Data);
}

std::vector<SwatProductData*> SwatProductViewModel::get() const
{
	return m_Datas;
}

SwatProductData* SwatProductViewModel::get(INVESTMENT _type) const
{
	return m_Datas[(int)_type];
}

bool SwatProductViewModel::Invest(INVESTMENT _Type)
{
	return m_Datas[(int)_Type]->Invest();
}
