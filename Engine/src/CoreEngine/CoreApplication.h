#pragma once
#include "CoreHeader.h"
#include "Logging.h"
#include "EventHandler/EventHeader.h"
#include "CoreEngine/Frame.h"

#define FN_BIND(fn) std::bind(&Engine::CoreApplication::fn,this,std::placeholders::_1)
namespace Engine {
	class ENGINE_API CoreApplication
	{
	public:
		CoreApplication();
		virtual ~CoreApplication();
		virtual void onEvent(const EventAbstract& e);
		virtual void run();
	protected:
		std::unique_ptr<Engine::Window> m_window;
	};

	//Defined by Client
	//Defined by Client
	std::unique_ptr<Engine::CoreApplication> createApplication();
}
