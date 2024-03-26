#include "CStandState.h"

void CStandState::Process(CPlayerObj* Target)
{
	POINT pTarget = { Target->m_vPos.x,Target->m_vPos.y };
	CVector2 pPos = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };






	CRect rect;
	rect.SetRect(pPos, 940, 540);

	if (!rect.ToRect(Target->m_RT) && m_pBoss->m_pActionList[STATE_TRACE]!=nullptr)
	{

		m_pBoss->SetTransition(EVENT_TRACE);
		return;
	}
	if (rect.ToRect(Target->m_RT) && m_pBoss->m_pActionList[STATE_ATTACK] != nullptr)
	{
     	m_pBoss->m_AttackSound->EffectSoundPlay();

		m_pBoss->SetTransition(EVENT_FINDTARGET);
		return;
	}
	if (m_pBoss->HealthPoint <= 0)
	{
		m_pBoss->m_DeadSound->EffectSoundPlay();
		m_pBoss->SetTransition(EVENT_DIE);
		

	}

	

}

CStandState::CStandState(CBoss* parent) : NpcState(parent)
{

}

CStandState::~CStandState()
{

}
