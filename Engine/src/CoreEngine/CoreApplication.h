#pragma once
#include "CoreHeader.h"
#include "Logging.h"
#include "EventHandler/EventHeader.h"
#include "CoreEngine/Frame.h"

namespace Engine {
	class ENGINE_API CoreApplication
	{
	public:
		CoreApplication();
		virtual ~CoreApplication();
		virtual void run();
	protected:
		std::unique_ptr<Engine::Window> m_window;
	};

	//Defined by Client
	//Defined by Client
	CoreApplication* CreateApplication();
}
