#pragma once
#include "CBoss.h"

class CTraceState : public NpcState
{
public:
	virtual void Process(CPlayerObj* Target);
public:
	CTraceState(CBoss* parent);
	virtual ~CTraceState();
};

