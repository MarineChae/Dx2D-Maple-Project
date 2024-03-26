#pragma once
#include"CSpriteObj.h"
#include"CParticle.h"
#include"CSoundMgr.h"



class CSkillEffect : public CSpriteUVObj
{
public:
	double m_Delay = 0.08;
	double m_AccumulatedTime = 0.0;
	int MaxSoundCount = 0;
	CSpriteUVObj* m_pSpriteUVObj;
	std::map<int, CSpriteUVObj*>	m_SpriteList;
	std::list<CParticle>		m_ParticleList;

	CSound* m_EffSound;


public:
	void    LoadEffect(CVector2 PlayerPos);
	virtual bool Frame();
	virtual bool Render(CVector3 PlayerPos);
	virtual bool Release();


};

