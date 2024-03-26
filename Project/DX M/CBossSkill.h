
#pragma once
#include"CSpriteObj.h"
#include"CParticle.h"
#include"CSoundMgr.h"



class CBossSkill : public CSpriteUVObj
{
public:
	int SKillDamage = 20000;
	double m_Delay = 1.095;
	double m_AccumulatedTime = 0.0;
	int MaxSoundCount = 0;
	CVector3  m_vDirection = { 1,1,0 };

public:
	CSpriteUVObj* m_pSpriteUVObj;
	std::map<int, CSpriteUVObj*>	m_SpriteList;
	std::list<CParticle>		m_ParticleList;

	//CSound* m_UseSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Use.mp3");
	//CSound* m_HitSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Hit.mp3");
public:
	void    LoadEff(CVector2 PlayerPos);
	void    LoadSkill(bool face, CVector2 PlayerPos);
	virtual bool Frame();
	virtual bool Render(bool face, CVector3 PlayerPos);
	virtual bool Release();

};