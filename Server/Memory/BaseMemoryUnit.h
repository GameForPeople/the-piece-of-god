#pragma once

#include "using_type.hh"

struct BaseMemoryUnit
{
	constexpr static size_t DATA_BUFFER_SIZE = 128;

	enum class MEMORY_UNIT_TYPE : _Buffer		/*int*/
	{
		RECV_FROM_CLIENT = 0x00,
		SEND_TO_CLIENT = 0x01,
		//TIMER_FUNCTION = 0x02,
		ENUM_SIZE
	};

	BaseMemoryUnit(const MEMORY_UNIT_TYPE memoryUnitType);
	virtual ~BaseMemoryUnit() = 0;

public:
	OVERLAPPED overlapped;
	WSABUF wsaBuf;

	const MEMORY_UNIT_TYPE memoryUnitType;	// All Memory Queue

	_Buffer dataBuf[DATA_BUFFER_SIZE];
};

//--------------------
// ClientMemory
//--------------------

struct ClientMemory 
	: public BaseMemoryUnit
{
	ClientMemory();
	~ClientMemory() = default;

public:
	_Buffer loadedBuf[DATA_BUFFER_SIZE];
	int loadedSize;

	SOCKET socket;

private:
	_Key key;

	_Id id;
	_Pw pw;
	_Nickname nickname;

	_Count winCount;
	_Count loseCount;
	
	_Money money;
};

//--------------------
// SendMemory
//--------------------

struct SendMemory
	: public BaseMemoryUnit
{
	SendMemory();
	~SendMemory() = default;
};

