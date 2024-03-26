#pragma once
#include "CScene.h"
#include"CParticle.h"

enum LazerState
{
	PRE=0,
	LOOP=1,
	END=2,
	NONE=3,
};

class C1PhaseScene : public CScene
{


public:
	std::unique_ptr<CMapObj> m_pSwooCore;
	std::vector <CSpriteUVObj*> m_pPortalList;
	std::vector<CSpriteUVObj*> m_pDropObjList;
	CSpriteUVObj*  m_pHitEff;
	std::vector < CSpriteUVObj*> m_pLazerList;
	CSound* m_ObjHitSound;
	LazerState LzState;
	CSound* m_LazerSound;
	double LzSkillCoolDown;
	double LzSkillHitDelay;
	double ChangeTime;
	CSpriteUVObj* m_pUVObj;

	double DropObjTimer =0.0;
	double DropObjCoolDown = 0.7;
	std::map<int, CSpriteUVObj*> m_SceneSpriteList;
	std::list< CParticle>		m_SceneParticleList;
	std::list< CParticle>		m_ObjParticleList;
	CParticle info;
	CParticle* DropObj;
	
public:
	void CreatePotal();
	void CreateDropObj();
	void CreateBackGround();
	void CreateFootHold();
	void CreateMapObj();
	void CreateBoss();
	void CreateParticle();
public:
	virtual bool Init();
	virtual bool Frame(CPlayerObj* Target);
	virtual bool Render();
	virtual bool Release();
};

