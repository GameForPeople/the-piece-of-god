#pragma once

#include "../Define/using_type.hh"

class BaseScene_InterFace abstract
{
public:
	BaseScene_InterFace() = default;
	virtual ~BaseScene_InterFace() = default;

	DISABLED_COPY(BaseScene_InterFace)
	DISABLED_MOVE(BaseScene_InterFace)

	virtual void ProcessPacket() = 0;
};

class BaseScene
	: public BaseScene_InterFace
{
public:
	enum class SCENE_TYPE : char
	{
		_0_TITLE_SCENE = 0,
		_1_LOGIN_SCENE = 1,
		_2_LOBBY_SCENE = 2,
		_3_ROOM_SCENE = 3,
		_4_GAME_SCENE = 4,
		ENUM_SIZE
	};

	BaseScene(SCENE_TYPE sceneType);

private:
	BaseScene::SCENE_TYPE sceneType;
};