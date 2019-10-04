#pragma once
#include "CoreHeader.h"
#include "Logging.h"
#include "EventHandler/EventHeader.h"
#include "CoreEngine/Window.h"

namespace Engine {
	class ENGINE_API CoreApplication
	{
	public:
		CoreApplication();
		virtual ~CoreApplication();
		virtual void run();
	};

	//Defined by Client
	//Defined by Client
	CoreApplication* CreateApplication();
}
