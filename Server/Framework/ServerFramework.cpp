#include "stdafx.h"
#include "../Define/stdafx.h"

#include "../Scene/BaseScene.h"

#include "ServerFramework.h"

#include "Scene/0_TitleScene/TitleScene.h"
#include "Scene/1_LoginScene/LoginScene.h"
#include "Scene/2_LobbyScene/LobbyScene.h"
#include "Scene/3_RoomScene/RoomScene.h"
#include "Scene/4_GameScene/GameScene.h"

ServerFramework::ServerFramework()
{
	using _SceneType = BaseScene::SCENE_TYPE;
	sceneCont.reserve(static_cast<char>(_SceneType::ENUM_SIZE));
	
	sceneCont.emplace_back(new TitleScene());
	sceneCont.emplace_back(new LoginScene());
	sceneCont.emplace_back(new LobbyScene());
	sceneCont.emplace_back(new RoomScene());
	sceneCont.emplace_back(new GameScene());

	assert(sceneCont.size() == _SceneType::ENUM_SIZE && "�̻����� SceneType�� �ֽ��ϴ�.");

	InitNetwork();
}

ServerFramework::~ServerFramework()
{
	for (auto& scene : sceneCont) {	delete scene; }
}

void ServerFramework::Run()
{
	// 7. Listen()!
	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, TEXT("listen()"));
}

void ServerFramework::InitNetwork()
{
	// 1. ���� �ʱ�ȭ
	WSADATA	wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, TEXT("WSAStartup()"));

	// 2. ����� �Ϸ� ��Ʈ ����
	if (hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0)
		; hIOCP == NULL) ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, TEXT("Create_IOCompletionPort()"));

	// 3. ��Ŀ ������ ���� �� IOCP ���.
	auto threadCount = std::thread::hardware_concurrency();
	workerThreadCont.reserve(threadCount);
	for (int i = 0; i < /* (int)si.dwNumberOfProcessors * 2 */ threadCount; ++i)
	{
		workerThreadCont.emplace_back(std::thread{ [&]() {this->WorkerThreadFuinction(); } });
	}

	// 4. ���� ����
	if (listenSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)
		; listenSocket == INVALID_SOCKET) ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, TEXT("socket()"));

	// 5. ���� ���� ��ü ����
	SOCKADDR_IN	serverAddr;
	ZeroMemory(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(LISTEN_PORT);

	// 6. ���� ����
	if (::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) ERROR_UTIL::Error(MAKE_SOURCE_LOCATION, TEXT("bind()"));
}

void ServerFramework::WorkerThreadFuinction()
{
	int retVal{};
	DWORD cbTransferred{};
	unsigned long long Key{};

	while (7)
	{

	}
}