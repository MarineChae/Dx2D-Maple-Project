#include "CDeadState.h"

void CDeadState::Process(CPlayerObj* Target)
{
	POINT pTarget = { Target->m_vPos.x,Target->m_vPos.y };
	CVector2 pPos = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };

	m_pBoss->Alive = false;
	ChageTime += g_fSecondPerFrame;
	if (ChageTime >= 5.5)
	{
		m_pBoss->Alive = true;
		m_pBoss->m_DeadSound->SoundStop();
		ChageTime = 0;
		m_pBoss->m_bVaild = false;
		m_pBoss->SetTransition(EVENT_SCENECHANGE);
	}
	if (m_pBoss->m_iTexIndex >= m_pBoss->m_pCSpriteDataList[m_pBoss->m_dwCurState].MaxUvSize-1 )
	{
		
		
		
		return;
	}





}

CDeadState::CDeadState(CBoss* parent) : NpcState(parent)
{

}

CDeadState::~CDeadState()
{

}
