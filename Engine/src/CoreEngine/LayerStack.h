#pragma once 
#include "CoreHeader.h"
#include <vector>
#include "Layer.h"

namespace Engine
{
	class ENGINE_API LayerStack
	{
	private:
		std::vector<Layer*> m_layers;
		unsigned int m_size = 0;
	public:
		LayerStack()=default;
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
		void popLayer(Layer* layer);
		void popOverlay(Layer* overlay);
		auto begin() { return m_layers.begin(); }
		auto end() { return m_layers.end(); }
		
	};

}