#pragma once
#include"CDefine.h"
#include <functional>
enum State
{
	STATE_STAND=0,
	STATE_TRACE=1,
	STATE_ATTACK=2,
	STATE_DEAD=3,
	STATE_SKILL1=4,
	STATE_SKILL2=5,
	STATE_SIZE

};
enum Event
{
	EVENT_TRACE = 0,
	EVENT_STOP = 1,
	EVENT_FINDTARGET=2,
	EVENT_DIE=3,
	EVENT_SCENECHANGE=4,
	EVENT_USESKILL1=5,
	EVENT_USESKILL2 = 6,
	EVENT_SIZE
};


class CFinitState
{
public:

	DWORD m_dwState;
	std::map <DWORD, DWORD>  m_Map;

public:
	DWORD	GetState() { return m_dwState; };
	void    AddTransition(DWORD inputEvent, DWORD outputStateID);
	DWORD	OutPut(DWORD inputEvent);


public:

	CFinitState(DWORD dwState);
	virtual ~CFinitState();


};

