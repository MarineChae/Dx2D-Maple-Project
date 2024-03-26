#include "CSKill1State.h"

void CSKill1State::Process(CPlayerObj* Target)
{

	CVector2 pTarget = { Target->m_vPos.x,Target->m_vPos.y };
	CVector2 pPos = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };

	CVector2 vDir = { pTarget.x - pPos.x ,0 };
	vDir.Normal();
	if (vDir.x < 1 && m_pBoss->IsDelay == false)
	{


		m_pBoss->FaceLeft = true;
		m_pBoss->FaceRight = false;


	}
	else if (vDir.x > 1 && m_pBoss->IsDelay == false)
	{

		m_pBoss->FaceLeft = false;
		m_pBoss->FaceRight = true;

	}
	

	//CRect rect;
	//rect.SetRect(pPos, m_pBoss->m_vScale.x , m_pBoss->m_vScale.y * 0.8);
	m_pBoss->m_SkillDelay += g_fSecondPerFrame;


	if (m_pBoss->HealthPoint <= 0)
	{
		m_pBoss->m_DeadSound->EffectSoundPlay();
		m_pBoss->SetTransition(EVENT_DIE);
		return;

	}  

	if (m_pBoss->m_SkillDelay >= 2.480)
	{
		m_pBoss->UseSkill1 = true;
  		m_pBoss->m_SkillCoolDown = 0;
		m_pBoss->m_SkillDelay = 0;
		
		m_pBoss->SetTransition(EVENT_TRACE);
	}
	



}

CSKill1State::CSKill1State(CBoss* parent) : NpcState(parent)
{
}

CSKill1State::~CSKill1State()
{
}
