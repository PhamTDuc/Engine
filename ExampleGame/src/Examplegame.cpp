#include<iostream>
#include<EngineHeader.h>
#include "CoreEngine/LayerStack.h"

class CustomLayer :public Engine::LayerAbstract
{public:
	CustomLayer(const char* name = "Custom Layer") :LayerAbstract(name) {};
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
	
		std::unique_ptr<Engine::Window> window = std::make_unique<Engine::Window>();
		
		m_window=std::move(window);
		m_window->run();
	
		glfwTerminate();
	}

};


Engine::CoreApplication* Engine::CreateApplication() 
{
	return new GuineaGame();
}