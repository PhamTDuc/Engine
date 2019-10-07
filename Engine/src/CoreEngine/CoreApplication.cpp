#include "CoreApplication.h"


namespace Engine {

	CoreApplication::CoreApplication()//:m_window(std::make_unique<Engine::Window>())
	{
	}


	CoreApplication::~CoreApplication()
	{
	}


	void CoreApplication::run() 
	{
		CORE_INFO("Game Engine created");
		CORE_INFO("Default Application");
	}
}