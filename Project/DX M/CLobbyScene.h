#pragma once
#include "CScene.h"
#include "CSpriteObj.h"
#include"CParticle.h"


class CLobbyScene : public CScene
{
public:
	/*std::vector<std::unique_ptr<CMapObj>>	m_MapList;*/




	std::map<int, CSpriteUVObj*> m_SceneSpriteList;
	std::list< CParticle>		m_SceneParticleList;
	CParticle info;
	int m_iSpriteIndex = 0;
public:
	void CreatePotal();
	void CreateBackTile();
	void CreateStaticObj();
	void CreateFootHold();
	bool CreateMapObj();

public:
	virtual bool CheckCollide(CRect& MapObj, CRect& other);
	virtual bool Init();
	virtual bool Frame(CPlayerObj* Target);
	virtual bool Render();
	virtual bool Release();
};

