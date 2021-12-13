#pragma once
#include"Subject.h"
#include"Nation.h"

class SubjectNation : public Subject {
public:
	static SubjectNation* Instance();
	~SubjectNation();

private:
	static SubjectNation* p_Instance;
	SubjectNation();
};