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

	assert(sceneCont.size() == _SceneType::ENUM_SIZE && "미생성된 SceneType이 있습니다.");
}

ServerFramework::~ServerFramework()
{
	for (auto& scene : sceneCont) {	delete scene; }
}

void ServerFramework::Run()
{

}