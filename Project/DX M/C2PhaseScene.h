#pragma once
#include "CScene.h"
#include "CSpriteObj.h"

class C2PhaseScene : public CScene
{
public:
	CSpriteUVObj* m_pHitEff;
	double DropObjTimer = 0.0;
	double DropObjCoolDown = 0.8;
	std::vector<CSpriteUVObj*> m_pDropObjList;
	std::list< CParticle>		m_ObjParticleList;
	std::map<int, CSpriteUVObj*> m_SceneSpriteList;
	CParticle info;
	CParticle* DropObj;
	CSound* m_ObjHitSound;
public:
	void CreateBackGround();
	void CreateFootHold();
	void CreateBoss();
	void CreateDropObj();
public:
	virtual bool Init();
	virtual bool Frame(CPlayerObj* Target);
	virtual bool Render();
	virtual bool Release();
};

//#pragma once
//#include "CScene.h"
//#include "CSpriteObj.h"
//
//class C3PhaseScene : public CScene
//{
//
//public:
//	void CreateBackGround();
//	void CreateFootHold();
//	void CreateBackTile();
//public:
//	virtual bool Init();
//	virtual bool Frame();
//	virtual bool Render();
//	virtual bool Release();
//};
