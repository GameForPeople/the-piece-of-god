#include "stdafx.h"

#include "BaseMemoryUnit.h"

BaseMemoryUnit::BaseMemoryUnit(const MEMORY_UNIT_TYPE memoryUnitType)
	: memoryUnitType(memoryUnitType)
	, overlapped()
	, wsaBuf()
	, dataBuf()
{
	wsaBuf.buf = dataBuf;
	wsaBuf.len = DATA_BUFFER_SIZE;
}

//--------------------
// ClientMemory
//--------------------

ClientMemory::ClientMemory()
	: BaseMemoryUnit(BaseMemoryUnit::MEMORY_UNIT_TYPE::RECV_FROM_CLIENT)
	, key(-1)
	, id()
	, pw()
	, nickname()
	, winCount()
	, loseCount()
	, money()
{
}


//--------------------
// SendMemory
//--------------------

SendMemory::SendMemory()
	: BaseMemoryUnit(BaseMemoryUnit::MEMORY_UNIT_TYPE::SEND_TO_CLIENT)
{
}


