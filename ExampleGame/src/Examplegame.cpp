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
	//void run()
	//{
	//	std::cout << "Hello GUINEA ENGINE";
	//	std::cin.get();
	//}
};


Engine::CoreApplication* Engine::CreateApplication() {
	return new GuineaGame();
}