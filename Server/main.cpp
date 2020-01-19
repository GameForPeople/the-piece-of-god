#include "stdafx.h"

#include "Framework/ServerFramework.h"

int main()
{
	std::unique_ptr<ServerFramework> serverFramework 
		= std::make_unique<ServerFramework>();

	serverFramework->Run();
}