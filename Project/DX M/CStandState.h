#pragma once
#include "CBoss.h"

class CStandState : public NpcState
{
public:
	virtual void Process(CPlayerObj* Target);
public:
	CStandState(CBoss* parent);
	virtual ~CStandState();
};

