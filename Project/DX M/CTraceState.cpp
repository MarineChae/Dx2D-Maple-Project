#include "CTraceState.h"

void CTraceState::Process(CPlayerObj* Target)
{

	CVector2 pTarget = { Target->m_vPos.x,Target->m_vPos.y };
	CVector2 pPos = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };

	CVector2 vDir;
	if (pTarget.x - pPos.x < 1)
	{
		vDir.x = -1;
		m_pBoss->FaceLeft = true;
		m_pBoss->FaceRight = false;
	}
	else
	{
		vDir.x = 1;
		m_pBoss->FaceLeft = false;
		m_pBoss->FaceRight = true;

	}	
	vDir.y = 0;

	CRect rect; 
	//숫자는 임시 시간되면 수정 예정
	rect.SetRect(pPos,846, 216);
	m_pBoss->m_SkillCoolDown += g_fSecondPerFrame;
	m_pBoss->m_Skill2CoolDown += g_fSecondPerFrame;
	if (m_pBoss->m_SkillCoolDown>=10.f)
	{
		
		m_pBoss->m_SkillSound->EffectSoundPlay();
		m_pBoss->SetTransition(EVENT_USESKILL1);
		return;

	}
	if (m_pBoss->m_Skill2CoolDown >= 15.f&&m_pBoss->m_pActionList[STATE_SKILL2]!=nullptr)
	{


		m_pBoss->SetTransition(EVENT_USESKILL2);
		return;

	}
	if (rect.ToRect(Target->m_RT))
	{
		

 		m_pBoss->SetTransition(EVENT_STOP);
		return;
	}
	if (m_pBoss->HealthPoint <= 0)
	{
		
		m_pBoss->SetTransition(EVENT_DIE);
		return;

	}
	


	m_pBoss->Move(vDir);
}

CTraceState::CTraceState(CBoss* parent) : NpcState(parent)
{
}

CTraceState::~CTraceState()
{
}
