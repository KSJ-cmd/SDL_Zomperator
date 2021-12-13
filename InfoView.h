#pragma once
#include<vector>
#include"InfoData.h"
class InfoView {
public:
	InfoView();
	~InfoView();
	void drawINF(InfoData* _infoData);
private:
	std::vector<int> m_Hps;
	std::vector<int> m_Wps;
	std::vector<int> m_Mds;
	std::vector<int> m_Fds;
};