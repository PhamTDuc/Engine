#pragma once
#include "CoreHeader.h"
#include <sstream>
#define BIT(x) 1<<x
#define EVENT_CLASS_TYPE(type) virtual const char* getName() const override {return #type;}\
EventType getEventType() const override { return EventType::##type; }

#define CATAGORY(catagory) int getFlags() const override{return catagory;}

namespace Engine {

	enum class EventType {
		None =0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};


	class ENGINE_API EventAbstract 
	{
	friend class EventDispatcher;
	protected:
		bool handled = false;
	public:
		virtual int getFlags() const = 0;
		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual std::string getEvent() const = 0;
		bool isInCategory(EventCategory category) const 
		{
			return getFlags() & category;
		}
		friend std::ostream& operator<<(std::ostream& os, const EventAbstract &event)
		{
			return os << event.getEvent();
		}
		

	};



	//Not available yet
	//Not available yet
	class EventDispatcher 
	{
	private:
		EventAbstract& m_event;
	public:
		EventDispatcher(EventAbstract& event) :m_event(event){}

		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_event.getEventType() == T::getEventType())
			{
				m_event.handled = func(static_cast<T&>(m_event));
				return true;
			}
			return false;
		}
	};
}


