#pragma once
#include "CPlayerObj.h"
#include"CMapObj.h"
#include"CParticle.h"
#include"CSkill.h"
#include"CWriter.h"
#include"CSoundMgr.h"
enum PlayerState
{
	PSTATE_STAND = 0,
	PSTATE_WALK = 1,
	PSTATE_JUMP = 2,
	PSTATE_PRONE =3,
	PSTATE_ATTACK = 4,
	PSTATE_SKILL1 = 5,
	PSTATE_DEAD=6,



};



class CPlayableCharacter : public CPlayerObj
{
public:
	bool IsTurnDelay = false;
public:
	PlayerState PState = PSTATE_STAND;
	bool BeforeDrop = false;
	bool IsAttack = false;
	bool IsDead = false;
	int DeathCount = 5;
	int MaxPlayerHP = 60000;
	int MaxPlayerMP = 2000;
	float PlayerMP;
	bool isInvincible = false;
	std::vector<CSpriteData> m_pCSpriteDataList;

	std::unique_ptr<CSpriteUVObj>m_pSpriteUVObj;
	std::unique_ptr<CSpriteUVObj>m_pUVObj = nullptr;

	int m_iSpriteIndex = 0;
	
	CSound* m_JumpSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Jumpsound.mp3");
	std::map<int, CSpriteUVObj*>	m_SpriteList;
	std::list<CParticle>		m_ParticleList;
	CMapObj PlayerHPBar;
	CMapObj PlayerMPBar;
public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render(bool face);
	virtual void Move(double fSecond);
	void ChangeState(PlayerState State);
};

