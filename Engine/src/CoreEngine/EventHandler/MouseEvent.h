#pragma once
#include "Event.h"

namespace Engine
{
	class ENGINE_API MouseMoved : public EventAbstract
	{
	private:
		float m_mouseX, m_mouseY;
	public:
		MouseMoved(float x, float y):m_mouseX(x),m_mouseY(y){}
		float getX() const { return m_mouseX; }
		float getY() const { return m_mouseY; }
		EVENT_CLASS_TYPE(MouseMoved)
		CATAGORY(EventCategoryMouse | EventCategoryInput)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "Mouse moved: X" << m_mouseX << " Y" << m_mouseY;
			return ss.str();
		}
	};

	class ENGINE_API MouseScrolled :public EventAbstract
	{
	private:
		float m_XOffset, m_YOffset;
	public:
		MouseScrolled(float x, float y):m_XOffset(x),m_YOffset(y){}
		EVENT_CLASS_TYPE(MouseScrolled);
		CATAGORY(EventCategoryMouse|EventCategoryInput)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "Mouse scrolled: X" << m_XOffset << " Y" << m_YOffset;
			return ss.str();
		}

	};

	class ENGINE_API MouseButton :public EventAbstract
	{
	protected:
		unsigned char m_button;
		MouseButton(int button):m_button(button){}
	public:
		int getMouseButton() const { return m_button; }
		CATAGORY(EventCategoryMouse|EventCategoryInput)
	};

	class ENGINE_API MouseButtonPressed :public MouseButton
	{
	public:
		MouseButtonPressed(int button):MouseButton(button){}
		EVENT_CLASS_TYPE(MouseButtonPressed);
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "MousePressed: "<<m_button;
			return ss.str();
		}
	};

	class ENGINE_API MouseButtonReleased:public MouseButton
	{
	public:
		MouseButtonReleased(int button):MouseButton(button){}
		EVENT_CLASS_TYPE(MouseButtonReleased)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "MouseReleased: " << m_button;
			return ss.str();
		}
	};
}