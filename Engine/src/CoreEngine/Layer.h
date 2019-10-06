#pragma once
#include "CoreHeader.h"
#include "CoreEngine/EventHandler/Event.h"

namespace Engine
{
	class ENGINE_API Layer
	{protected:
		const char* m_name;
	public:
		Layer(const char* name = "Layer") :m_name(name) {};
		virtual ~Layer() = default;

		virtual void onAttach() = 0;
		virtual void onDetach() = 0;
		virtual void onUpdate() = 0;
		virtual void onEvent(const EventAbstract& event) = 0;

		friend std::ostream& operator<<(std::ostream& out, const Layer& layer)
		{
			out << layer.m_name;
			return out;
		}
	}; 
}