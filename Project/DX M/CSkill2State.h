#pragma once
#include "CBoss.h"

class CSKill2State : public NpcState
{
public:
	virtual void Process(CPlayerObj* Target);
public:
	CSKill2State(CBoss* parent);
	virtual ~CSKill2State();
};

