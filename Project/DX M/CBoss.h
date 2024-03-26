#pragma once
#include "CPlayerObj.h"
#include"CMapObj.h"
#include"CWriter.h"
#include"CFSM.h"
#include"CSoundMgr.h"
#include"CBossSkill.h"
class CBoss;

class NpcState
{
public:
	CBoss* m_pBoss;

public:
	virtual void Process(CPlayerObj* obj)=0;

public:
	NpcState(CBoss* pBoss) : m_pBoss(pBoss)
	{

	}
	virtual ~NpcState() {};
};



class CBoss : public CPlayerObj
{
public:
	CSound* m_AttackSound;
	CSpriteUVObj* m_AttackEff;
	CSound* m_SkillSound;
	CSound* m_DeadSound;
	NpcState* m_pAction;
	NpcState* m_pBeforeAction;
	NpcState* m_pActionList[STATE_SIZE];
	CFSM* m_pFSM;
	DWORD		m_dwCurState;
public:
	bool Alive = true;
	bool HitAttack = false;
	double m_AttackDelay = 2.6;
	double AfterDelay = 0.0;
	bool IsDelay = false;
	bool IsAttack = false;
	double m_SkillCoolDown = 0.0;
	double m_SkillDelay = 0.0;
	double m_Skill2CoolDown = 0.0;
	double m_Skill2Delay = 0.0;

	bool isflip = false;
	bool BeforeLeft = false;
	bool BeforeRight = false;
	bool UseSkill = false;
	bool UseSkill1 = false;
	bool UseSkill2 = false;

	int MaxBossHP;
	CMapObj BossHPBar;
public:
	std::vector<CSpriteData> m_pCSpriteDataList;
	std::unique_ptr<CSpriteUVObj>m_pSpriteUVObj;
	std::unique_ptr<CSpriteUVObj>m_pUVObj = nullptr;
	int m_iSpriteIndex = 0;
	std::map<int, CSpriteUVObj*>	m_SpriteList;
	std::list<CParticle>		m_ParticleList;
	std::vector<CBossSkill*>    m_pBossSkillList;
	bool isHit = false;

public:
	
public:
	virtual void Process(CPlayerObj* obj);
	void FSM(int Index);
	void SetTransition(DWORD Event);
public:
	virtual bool Init();
	virtual bool Frame();
	void Move(CVector2 vTarget);
	virtual bool Render(bool face);
};

