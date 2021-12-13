#pragma once
#include<memory>
#include<vector>
#include"Nation.h"
class NationHandler {
public:
	NationHandler();
	static std::vector<Nation*>& getNations();
private:
	static std::vector<Nation*> m_Nations;
};