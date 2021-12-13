#include"Cmd_Supply.h"

Cmd_Supply::Cmd_Supply(IUse* _use,ITake* _take)
	:m_use(_use),m_Take(_take)
{
}

Cmd_Supply::~Cmd_Supply()
{
}

void Cmd_Supply::execute()
{
	if (m_use->Use())
		m_Take->Take();
}
