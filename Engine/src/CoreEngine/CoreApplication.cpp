#include "CoreApplication.h"


namespace Engine {

	CoreApplication::CoreApplication()
	{
	}


	CoreApplication::~CoreApplication()
	{
	}


	void CoreApplication::run() 
	{
		CORE_INFO("Game Engine created");
		Engine::KeyPressed e(332, false);
		CORE_INFO(e);
		CORE_INFO("Initialize GLFW and GLAD");
	}
}