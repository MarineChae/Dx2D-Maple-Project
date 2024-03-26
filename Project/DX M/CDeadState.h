#pragma once
#include "CBoss.h"

class CDeadState : public NpcState
{
public:
	double ChageTime;
public:
	virtual void Process(CPlayerObj* Target);
public:
	CDeadState(CBoss* parent);
	virtual ~CDeadState();
};

