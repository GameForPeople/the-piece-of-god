#pragma once

#include "../Define/using_type.hh"

class BaseScene;

//iocp
class ServerFramework
{
	const unsigned short LISTEN_PORT = 9000;

public:
	ServerFramework();
	~ServerFramework();

	DISABLED_COPY(ServerFramework)
	DISABLED_MOVE(ServerFramework)

public:
	void Run();

private:
	std::vector<_OWNER_PTR BaseScene*> sceneCont;

#pragma region [IOCP]
private:
	void InitNetwork();
	void WorkerThreadFuinction();


	HANDLE hIOCP;
	SOCKET listenSocket;

	std::vector<std::thread> workerThreadCont;
#pragma endregion
};
