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
	void onEvent(const Engine::EventAbstract& e) override
	{
		CLIENT_INFO(e);

	}
	void run() override
	{
		CORE_INFO("Game Engine created");
		Engine::KeyPressed e(332, true);
		CORE_INFO(e);
		Engine::LayerStack stack;

		CustomLayer layer("Layer 1");
		CORE_INFO(layer);
	
		std::unique_ptr<Engine::Window> window = std::make_unique<Engine::Window>();
		
		m_window=std::move(window);
		m_window->setEventCallback(FN_BIND(onEvent));
		m_window->run();

		glfwTerminate();
	}

};
std::unique_ptr<Engine::CoreApplication> Engine::createApplication() 
{
	std::unique_ptr<Engine::CoreApplication> app(new GuineaGame());
	return std::move(app);
}