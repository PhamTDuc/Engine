#pragma once
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
	int main(int argc, char** argv) {
		printf("Guinea Engine Running\n");

		Engine::Logging::Init();
		CORE_INFO("Initilized Logger");
		auto app = Engine::CreateApplication();
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		CLIENT_INFO("Initialized {0} {1}", "GAME","GUINEA PIG");
		CORE_INFO("Initialize GLFW and GLAD");
		glfwSetErrorCallback(error_callback);
		if (!glfwInit())
		{
			CORE_ERROR("Can't initialize GLFW");
		}
		//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		//{
		//	CORE_ERROR("Can't initalize GLAD");
		//}
		app->run();
		delete app;
	}


#else
	#error "GUINEA ENGINE ONLY SUPORT 64 BIT WINDOW PLATFORM"
#endif