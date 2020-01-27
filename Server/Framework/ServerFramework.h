#pragma once

#include "../Define/using_type.hh"

class BaseScene;
struct ClientMemory;
struct SendMemory;

//iocp
class ServerFramework
{
	static constexpr unsigned short LISTEN_PORT = 9000;
	static constexpr unsigned short MAX_CLIENT = 10000;
	static constexpr unsigned short MAX_SEND_POOL_SIZE = 10000;

public:
	ServerFramework();
	~ServerFramework();

	DISABLED_COPY(ServerFramework)
	DISABLED_MOVE(ServerFramework)

public:
	void Run();

private:
	std::vector<_OWNER_PTR BaseScene*> sceneCont;

#pragma region [Network - IOCP]
private:
	void InitNetwork();
	void WorkerThreadFunction();
	void AcceptThreadFunction();

	HANDLE hIOCP;
	SOCKET listenSocket;

	std::vector<std::thread> workerThreadCont;
	std::thread acceptThread;

	concurrency::concurrent_queue<SendMemory*> sendMemoryPool;
#pragma endregion

#pragma region [Client Cont]
private:
	std::vector<ClientMemory> clientCont;
	concurrency::concurrent_queue<_Key> clientKeyPool;
#pragma endregion

	void InitManager();

};