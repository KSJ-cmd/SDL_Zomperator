#pragma once
#include"ResourceData.h"
class DataView;
class DataControl {
public:
	static DataControl* Instance();
	DataControl(const DataControl& src);
	~DataControl();
	void Update();
	void Draw();
	ResourceData* get();
private:
	DataControl();
	static DataControl* p_Instance;
	DataControl& operator=(const DataControl& rsh) {}
	ResourceData* m_ResourceData;
	DataView* m_DataView;
};