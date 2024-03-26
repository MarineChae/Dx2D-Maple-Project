#pragma once
#include "CBoss.h"

class CAttackState : public NpcState
{
public:
	virtual void Process(CPlayerObj* Target);
public:
	CAttackState(CBoss* parent);
	virtual ~CAttackState();
};

