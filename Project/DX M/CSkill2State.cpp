#include "CSKill2State.h"

void CSKill2State::Process(CPlayerObj* Target)
{

	CVector2 pTarget = { Target->m_vPos.x,Target->m_vPos.y };
	CVector2 pPos = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };

	CVector2 vDir = { pTarget.x - pPos.x ,0 };
	vDir.Normal();
	if (vDir.x <=0 && m_pBoss->IsDelay == false)
	{
		m_pBoss->FaceLeft = true;
		m_pBoss->FaceRight = false;
		Target->m_vPos.x += 700 * g_fSecondPerFrame;
	}
	else if (vDir.x > 0 && m_pBoss->IsDelay == false)
	{
		Target->m_vPos.x -= 700 * g_fSecondPerFrame;
		m_pBoss->FaceLeft = false;
		m_pBoss->FaceRight = true;

	}


	//CRect rect;
	//rect.SetRect(pPos, m_pBoss->m_vScale.x , m_pBoss->m_vScale.y * 0.8);
	m_pBoss->m_Skill2Delay += g_fSecondPerFrame;


	if (m_pBoss->HealthPoint <= 0)
	{
		m_pBoss->m_DeadSound->EffectSoundPlay();
		m_pBoss->SetTransition(EVENT_DIE);
		return;

	}

	if (m_pBoss->m_Skill2Delay >= 0.81)
	{
		m_pBoss->UseSkill2 = true;
		m_pBoss->m_Skill2CoolDown = 0;
		m_pBoss->m_Skill2Delay = 0;

		m_pBoss->SetTransition(EVENT_TRACE);
	}




}

CSKill2State::CSKill2State(CBoss* parent) : NpcState(parent)
{
}

CSKill2State::~CSKill2State()
{
}
