#pragma once
#include "CBoss.h"

class CMoveState : public NpcState
{
public:
	CVector2 m_vTarget;
public:
	virtual void Process(CPlayerObj* Target);
public:
	CMoveState(CBoss* parent);
	virtual ~CMoveState();
};

