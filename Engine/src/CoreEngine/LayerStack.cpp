#include "LayerStack.h"

Engine::LayerStack::~LayerStack()
{
	for (Layer* layer : m_layers)
	{
		layer->onDetach();
	}
}

void Engine::LayerStack::pushLayer(Layer* layer)
{
	m_layers.emplace(m_layers.begin() + m_size, layer);
	m_size++;
	layer->onAttach();
}

void Engine::LayerStack::pushOverlay(Layer* overlay)
{
	m_layers.emplace_back(overlay);
	overlay->onAttach();
}

void Engine::LayerStack::popLayer(Layer* layer)
{
	auto it = std::find(m_layers.begin(), m_layers.begin() + m_size, layer);
	if (it != m_layers.begin() + m_size)
	{
		layer->onDetach();
		m_layers.erase(it);
		m_size--;
	}
}

void Engine::LayerStack::popOverlay(Layer* overlay)
{
	auto it = std::find(m_layers.begin(), m_layers.begin() + m_size, overlay);
	if (it != m_layers.begin() + m_size)
	{
		overlay->onDetach();
		m_layers.erase(it);
	}

}
