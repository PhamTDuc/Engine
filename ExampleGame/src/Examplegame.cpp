#include<iostream>
#include <EngineHeader.h>

class GuineaGame :public Engine::CoreApplication
{
public:
	GuineaGame()
	{
	};
	~GuineaGame()
	{
	}
	void run()
	{
		CORE_INFO("Game Engine created");
		Engine::KeyPressed e(332, true);
		CORE_INFO(e);
	
		Engine::Window window;
		window.run();
		glfwTerminate();
	}

};


Engine::CoreApplication* Engine::CreateApplication() 
{
	return new GuineaGame();
}