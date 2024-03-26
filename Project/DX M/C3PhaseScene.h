#pragma once
#include "CScene.h"


class C3PhaseScene : public CScene
{
public:
	CSpriteUVObj* m_pHitEff;
	double DropObjTimer = 0.0;
	double DropObjCoolDown = 5.0;
	std::vector<CSpriteUVObj*> m_pDropObjList;
	std::list< CParticle>		m_ObjParticleList;
	std::map<int, CSpriteUVObj*> m_SceneSpriteList;
	CParticle info;
	CParticle* DropObj;
	CSound* m_ObjHitSound;
public:
	void CreateTile();
	void CreateGround();
	void CreateHold();
	void CreateDropObj();

public:
	void CreateBoss();
	virtual bool Init();
	virtual bool Frame(CPlayerObj* Target);
	virtual bool Render();
	virtual bool Release();
};

