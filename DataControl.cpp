
#include"DataControl.h"
#include"DataView.h"
DataControl* DataControl::p_Instance = nullptr;
DataControl* DataControl::Instance()
{
	if (p_Instance == nullptr) {
		p_Instance = new DataControl();
	}
	return p_Instance;
}
DataControl::DataControl()
	:m_ResourceData(new ResourceData(new Weapon(3),new Medicine(3),new Food(3)))
	,m_DataView(new DataView(this))
{
}

DataControl::DataControl(const DataControl& src)
	:m_ResourceData(nullptr)
	,m_DataView(nullptr)
{
	m_DataView = new DataView(*src.m_DataView);
	m_ResourceData = new ResourceData(
		new Weapon(src.m_ResourceData->getWP()->get())
		, new Medicine(src.m_ResourceData->getMD()->get())
		, new Food(src.m_ResourceData->getFD()->get()));
}

DataControl::~DataControl()
{
	delete m_DataView;
	delete m_ResourceData;
	delete p_Instance;
}

void DataControl::Update()
{
}

void DataControl::Draw()
{
	m_DataView->Draw();
}

ResourceData* DataControl::get()
{
	return m_ResourceData;
}
