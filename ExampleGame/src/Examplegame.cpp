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
		Engine::KeyPressed e(332, false);
		CORE_INFO(e);
	
		Engine::Window window;
	}
};


Engine::CoreApplication* Engine::CreateApplication() {
	return new GuineaGame();
}