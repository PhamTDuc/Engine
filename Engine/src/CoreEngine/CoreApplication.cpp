#include "CoreApplication.h"
#include "Logging.h"
#include "EventHandler/EventHeader.h"

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
		while(true)
		{ }
	}
}