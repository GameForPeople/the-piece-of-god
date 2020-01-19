#pragma once

#include "../Define/using_type.hh"

class BaseScene;

class ServerFramework
{
public:
	ServerFramework();
	~ServerFramework();

	DISABLED_COPY(ServerFramework)
	DISABLED_MOVE(ServerFramework)

public:
	void Run();

private:
	std::vector<_OWNER_PTR BaseScene*> sceneCont;
};