#pragma once
#include "CoreHeader.h"
#include "Logging.h"
#include "CoreApplication.h"
#include "EventHandler/EventHeader.h"


#ifdef ENGINE_PLATFORM_WINDOW 
	Engine::CoreApplication* Engine::CreateApplication();
	int main(int argc, char** argv) {
		printf("Guinea Engine Running\n");

		Engine::Logging::Init();
		CORE_INFO("Initilized Logger");
		auto app = Engine::CreateApplication();
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		app->run();
		delete app;
	}


#else
	#error "GUINEA ENGINE ONLY SUPORT 64 BIT WINDOW PLATFORM"
#endif