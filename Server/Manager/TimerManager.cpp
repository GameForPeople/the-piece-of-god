#include "stdafx.h"

#include "TimerManager.h"

TimerManager::TimerManager()
{
}

TimerManager::~TimerManager()
{
}

void TimerManager::TimerThreadFunction()
{
	timerThread = std::thread{ []() 
	{
		while (7)
		{

		}
	} };
}