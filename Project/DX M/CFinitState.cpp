#include "CFinitState.h"

void CFinitState::AddTransition(DWORD inputEvent, DWORD outputStateID)
{
	m_Map[inputEvent] = outputStateID;
}

DWORD CFinitState::OutPut(DWORD inputEvent)
{
	auto iter = m_Map.find(inputEvent);
	if (iter == m_Map.end())
	{
		return -1;
	}


	return m_Map[inputEvent];
}

CFinitState::CFinitState(DWORD dwState) : m_dwState(dwState)
{
}
CFinitState::~CFinitState() 
{
	std::map < DWORD, DWORD >::iterator	iter, iterPrev;
	iter = m_Map.begin();
	while (iter != m_Map.end())
	{
		iterPrev = iter++;

		m_Map.erase(iterPrev);
	}
}