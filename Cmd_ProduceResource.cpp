#include"Cmd_ProduceResource.h"
#include"Data.h"
#include"DataControl.h"
Cmd_ProduceResource::Cmd_ProduceResource(Button* _button, ProductData* _ProductData)
	:m_Button(_button),m_ProductData(_ProductData)
{
}

Cmd_ProduceResource::~Cmd_ProduceResource()
{
	std::cout << "Cmd_ProduceResource delete" << std::endl;
}

void Cmd_ProduceResource::execute()
{
	std::cout << "Cmd_ProduceResource " << std::endl;
	if (Data::Instance()->useMoney(m_ProductData->getPrice())) {
		switch (m_ProductData->getType())
		{
		case PRODUCT_PRICE::WP:
			DataControl::Instance()->get()->takeWP(m_ProductData->getAmount());
			m_ProductData->Producing();
			break;
		case PRODUCT_PRICE::FD:
			DataControl::Instance()->get()->takeFD(m_ProductData->getAmount());
			m_ProductData->Producing();
			break;
		case PRODUCT_PRICE::MD:
			DataControl::Instance()->get()->takeMD(m_ProductData->getAmount());
			m_ProductData->Producing();
			break;
		default:
			break;
		}
	}
}
