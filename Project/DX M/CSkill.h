#pragma once
#include"CSpriteObj.h"
#include"CParticle.h"
#include"CSoundMgr.h"
#include"DamageIndicator.h"


class CSkill : public CSpriteUVObj
{
public:
	int SKillDamage =2439518;
	double m_Delay = 0.095;
	double m_AccumulatedTime = 0.0;
	int MaxSoundCount = 0;
	float UseMp = 50;

public:
	CSpriteUVObj*  m_pSpriteUVObj;
	std::map<int, CSpriteUVObj*>	m_SpriteList;
	std::list<CParticle>		m_ParticleList;

	CSound* m_UseSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Use.mp3");
	//CSound* m_HitSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Hit.mp3");
public:
	void    LoadSkill(bool face, CVector2 PlayerPos);
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render(bool face,CVector3 PlayerPos);
	virtual bool Release();
	
};