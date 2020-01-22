#pragma once

#include "using_type.hh"

class TimerManager
{
public:
	enum class TIME
	{
		SECOND = 10,
		MINUTE = 600,

	};
	
	TimerManager();
	~TimerManager();

	DISABLED_COPY(TimerManager)
	DISABLED_MOVE(TimerManager)

	void TimerThreadFunction();

private:
	std::thread timerThread;

	concurrency::concurrent_queue<TimerUnit*> timerMemoryPool;
};