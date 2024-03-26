#include "CAttackState.h"


void CAttackState::Process(CPlayerObj* Target)
{
	
	CVector2 pTarget = { Target->m_vPos.x,Target->m_vPos.y };
	CVector2 pPos = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };
	m_pBoss->BeforeLeft = m_pBoss->FaceLeft;
	m_pBoss->BeforeRight = m_pBoss->FaceRight;
	CVector2 vDir = { pTarget.x - m_pBoss->m_vPos.x ,0 };
	vDir.Normal();
	if (vDir.x <= 0&&m_pBoss->IsDelay == false)
	{
	
		
		 m_pBoss->FaceLeft = true;
		m_pBoss->FaceRight = false;
		
	
	}
	else if(vDir.x > 0&& m_pBoss->IsDelay == false) 
	{
		
		m_pBoss->FaceLeft = false;
		m_pBoss->FaceRight = true;

	}
	if (m_pBoss->FaceRight)
	{
		pPos.x += 300.0f;
	

	}
	else
	{
		pPos.x -= 300.0f;

	}
	if (m_pBoss->BeforeLeft!= m_pBoss->FaceLeft|| m_pBoss->BeforeRight!= m_pBoss->FaceRight)
	{
		
		m_pBoss->isflip = true;
	}
	m_pBoss->IsDelay = true;
	CRect rect;
	rect.SetRect(pPos, 450, 350);
	m_pBoss->AfterDelay += g_fSecondPerFrame;
	m_pBoss->m_SkillCoolDown += g_fSecondPerFrame;
	m_pBoss->m_Skill2CoolDown += g_fSecondPerFrame;
	if (rect.ToRect(Target->m_RT)&&m_pBoss->AfterDelay > 0.9 && m_pBoss->AfterDelay < 1.3&& m_pBoss->HitAttack == false)
	{
		m_pBoss->HitAttack = true;
		m_pBoss->m_pBossSkillList[2]->LoadEff({ Target->m_vPos.x,Target->m_vPos.y });
		Target->HealthPoint -= 20000;
		
	}
	if (m_pBoss->AfterDelay > 0.9 && m_pBoss->AfterDelay < 1.3&&m_pBoss->HitAttack == true)
	{
		if (m_pBoss->FaceRight == true)
			Target->m_vPos.x += 900* g_fSecondPerFrame;
		else
			Target->m_vPos.x -= 900* g_fSecondPerFrame;
	}
	if (rect.ToRect(Target->m_RT) && m_pBoss->AfterDelay >= m_pBoss->m_AttackDelay)
	{
		m_pBoss->HitAttack = false;
		m_pBoss->IsDelay = false;
		m_pBoss->m_AttackSound->EffectSoundPlay();
		m_pBoss->AfterDelay = 0;
		m_pBoss->SetTransition(EVENT_FINDTARGET);
		return;
	}
	
	if (!rect.ToRect(Target->m_RT)&& m_pBoss->AfterDelay>=m_pBoss->m_AttackDelay)
	{
		m_pBoss->HitAttack = false;
		m_pBoss->IsDelay = false;

		m_pBoss->AfterDelay = 0;
		m_pBoss->SetTransition(EVENT_TRACE);
		return;
	}


	if (m_pBoss->HealthPoint <= 0)
	{
		m_pBoss->m_DeadSound->EffectSoundPlay();
		m_pBoss->SetTransition(EVENT_DIE);
		return;

	}

}

CAttackState::CAttackState(CBoss* parent) : NpcState(parent)
{
}

CAttackState::~CAttackState()
{
}
