#pragma once
#include "Frame.h"
#include "CoreHeader.h"
#include "Logging.h"
#include "CoreApplication.h"
#include "EventHandler/EventHeader.h"

void error_callback(int error, const char* des)
{
	CORE_ERROR(des);
}

#ifdef ENGINE_PLATFORM_WINDOW 
	Engine::CoreApplication* Engine::CreateApplication();
	//int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
	int main(int argc,const char* argv[])
	{
		printf("Guinea Engine Running\n");

		Engine::Logging::Init();
		CORE_INFO("Initilized Logger");
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		CORE_INFO("Initialize GLFW and GLAD");
		//glfwSetErrorCallback(error_callback);
		auto app = Engine::CreateApplication();
		app->run();
		delete app;
	}


#else
	#error "GUINEA ENGINE ONLY SUPORT 64 BIT WINDOW PLATFORM"
#endif