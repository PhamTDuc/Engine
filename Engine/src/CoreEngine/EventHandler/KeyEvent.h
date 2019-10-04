#pragma once
#include "Event.h"

namespace Engine {

	class ENGINE_API KeyEvent : public EventAbstract 
	{
	protected:
		int m_KeyCode;
		KeyEvent(int keycode):m_KeyCode(keycode){}
	public:
		CATAGORY(EventCategoryInput|EventCategoryKeyboard)
		int getKeyCode() const { return m_KeyCode;}

	};


	class ENGINE_API KeyPressed : public KeyEvent
	{
	private:
		bool m_repeated = false;
	public:
		KeyPressed(int keycode, bool repeat) :KeyEvent(keycode), m_repeated(repeat){}
		EVENT_CLASS_TYPE(KeyPressed)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "KeyPressed:" << m_KeyCode << " repeated: " << m_repeated;
			return ss.str();
		}

	};

	class ENGINE_API KeyReleased : public KeyEvent
	{
	public:
		KeyReleased(int keycode):KeyEvent(keycode){}
		EVENT_CLASS_TYPE(KeyReleased)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "KeyReleased: " << m_KeyCode;
			return ss.str();

		}
		
		
	};

	class ENGINE_API KeyTyped :public KeyEvent
	{
	public:
		KeyTyped(int keycode):KeyEvent(keycode){}
		EVENT_CLASS_TYPE(KeyTyped)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "KeyTyped: " << m_KeyCode;
			return ss.str();

		}

	};
}

