#pragma once
#include"CSpriteObj.h"
#include"CParticle.h"
#include"CSoundMgr.h"
#include"CBoss.h"
#include"CPlayableCharacter.h"
#include"CSoundMgr.h"

class DamageIndicator;
class C5thSkill : public CSpriteUVObj
{
public:
	int SKillDamage = 4138592;
	double m_Delay = 0.095;
	double m_AccumulatedTime = 0.0;
	float UseMP = 500;
	double SkillCollDown = 0;
	bool Isok = false;
	int MaxSoundCount = 0;
	bool IsUse = false;
	int m_Index = 0;
	double m_HitDelay = 0;
public:
	CSpriteUVObj*  m_pSkillUVObj;
	std::vector<CSpriteUVObj*> m_pSpriteUVObj;
	std::vector<CSound*> m_SoundList;

	CSound* m_HitSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/5th/5thHit.mp3");

public:
	void    LoadSkill(bool face, CVector2 PlayerPos);
	virtual bool Init();
	virtual bool Frame(CBoss* boss, CPlayableCharacter* player, std::vector<std::shared_ptr<DamageIndicator>>);
	virtual bool Render(bool face, CVector3 PlayerPos);
	virtual bool Release();

};