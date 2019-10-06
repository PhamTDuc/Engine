#pragma once 
#include "CoreHeader.h"
#include <vector>
#include "Layer.h"

namespace Engine
{
	class ENGINE_API LayerStack
	{
	private:
		std::vector<LayerAbstract*> m_layers;
		unsigned int m_size = 0;
	public:
		LayerStack()=default;
		~LayerStack();

		void pushLayer(LayerAbstract* layer);
		void pushOverlay(LayerAbstract* overlay);
		void popLayer(LayerAbstract* layer);
		void popOverlay(LayerAbstract* overlay);
		auto begin() { return m_layers.begin(); }
		auto end() { return m_layers.end(); }
		
	};

}