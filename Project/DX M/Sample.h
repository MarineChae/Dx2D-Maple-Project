#pragma once
#include"CCore.h"
#include"CMapObj.h"
#include"CPlayableCharacter.h"
#include"CSoundMgr.h"
#include"CInput.h"
#include"CLobbyScene.h"
#include"C1PhaseScene.h"
#include"C2PhaseScene.h"
#include"C3PhaseScene.h"
#include"CSkill.h"
#include"CBoss.h"
#include"CBossSkill.h"
#include"CSkillEffect.h"
#include"C5thSkill.h"
#include"CUI.h"
#include"DamageIndicator.h"

enum ClearEnum
{
	None,
	Clear,
	Fail
};

class Sample : public CCore
{

public:
	double ClearTime;

	std::unique_ptr<CPlayableCharacter>		m_pPlayer = make_unique<CPlayableCharacter>();
	//std::unique_ptr<CBoss>		m_pBoss = make_unique<CBoss>();
	//std::vector<CBossSkill*>    m_pBossSkillList;

	std::unique_ptr<CSkill>		m_pSkillEff;
	std::unique_ptr<CSpriteUVObj>		m_pSpriteUVObj;
	
	CScene* m_PresentScene = nullptr;
	std::shared_ptr<CScene> m_pLobbyScene = nullptr;
	std::shared_ptr<CScene> m_p1PhaseScene = nullptr;
	std::shared_ptr<CScene> m_p2PhaseScene = nullptr;
	std::shared_ptr<CScene> m_p3PhaseScene = nullptr;
	std::vector<std::shared_ptr<CUI>> m_pUIList;
	std::shared_ptr<CUI> DisableSkillUI;
	std::shared_ptr<CUI> DisableElixer;
	CSpriteUVObj* m_UVObj;

	CSkill PlayerSkill;
	CSkillEffect SkillEff;
	CObject* BossHP;

	std::map<int, CSpriteUVObj*>	m_SpriteList;
	std::list<CParticle>		m_ParticleList;

	CSound* m_BGM;
	CSound* m_EffetSound;

	C5thSkill howling;

	std::vector<std::shared_ptr<DamageIndicator>> m_lDamageIndicator;

	std::vector<std::shared_ptr<CSpriteUVObj>> SpriteUI;


	std::shared_ptr<CSpriteUVObj> ClearUI;
	std::shared_ptr<CSpriteUVObj> FailUI;


	double PotionCoolDown = 5;
	
	bool ClearPlay = false;
	ClearEnum IsClear = None;
	float UITime = 0.0f;
	bool isRight;
	int m_iTexIndex = 0;

	int minute = 0;
	int sec = 0;
public:
	void CreateBackTile();
	void CreateStaticObj();
	void CreateFootHold();
	
	bool CreatePlayer();
	bool CreateBGM();
	bool CreateBoos();
public:

	bool Init();
	bool Frame();
	bool Render();
	bool Release();



};

