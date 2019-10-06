#include<iostream>
#include<EngineHeader.h>
#include "CoreEngine/LayerStack.h"

class CustomLayer :public Engine::Layer
{public:
	CustomLayer(const char* name = "Custom Layer") :Layer(name) {};
	~CustomLayer() = default;

	void onAttach() {};
	void onDetach() {};
	void onUpdate() {};
	void onEvent(const Engine::EventAbstract & event) {};


};

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
		Engine::LayerStack stack;

		CustomLayer layer("Layer 1");
		CORE_INFO(layer);
	
		Engine::Window window("HelloWindow");
		window.run();
	
		glfwTerminate();
	}

};


Engine::CoreApplication* Engine::CreateApplication() 
{
	return new GuineaGame();
}