#include "SubjectNation.h"


SubjectNation* SubjectNation::p_Instance = nullptr;

SubjectNation* SubjectNation::Instance()
{
	if (p_Instance == nullptr)
	{
		p_Instance = new SubjectNation();
	}

	return p_Instance;
}

SubjectNation::~SubjectNation()
{
}

SubjectNation::SubjectNation()
	:Subject()
{
}
