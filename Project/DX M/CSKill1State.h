#pragma once
#include "CBoss.h"

class CSKill1State : public NpcState
{
public:
	virtual void Process(CPlayerObj* Target);
public:
	CSKill1State(CBoss* parent);
	virtual ~CSKill1State();
};

