#pragma once

class IUse {
public:
	virtual ~IUse() {}
	virtual bool Use() = 0;
};