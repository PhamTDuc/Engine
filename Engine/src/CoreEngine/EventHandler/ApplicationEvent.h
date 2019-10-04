#pragma once
#include "Event.h"


namespace Engine
{
	class ENGINE_API WindowResize :public EventAbstract
	{
	private:
		unsigned int m_width, m_height;
	public:
		WindowResize(unsigned int width, unsigned int height):m_width(width),m_height(height){}
		unsigned int getWidth() const { return m_width;}
		unsigned int getHeight() const { return m_height;}
		EVENT_CLASS_TYPE(WindowResize);
		CATAGORY(EventCategoryApplication);
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "WindowResize: width" << m_width << " height" << m_height;
			return ss.str();
		}
	};

	class ENGINE_API WindowClose :public EventAbstract
	{
		WindowClose() {}
		EVENT_CLASS_TYPE(WindowClose)
		CATAGORY(EventCategoryApplication)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "WindowClose";
			return ss.str();
		}
	};

	class ENGINE_API AppTick :public EventAbstract
	{
	public:
		AppTick(){}
		EVENT_CLASS_TYPE(AppTick)
		CATAGORY(EventCategoryApplication)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "AppTick";
			return ss.str();
		}
	};

	class ENGINE_API AppUpdate :public EventAbstract
	{
	public:
		AppUpdate(){}
		EVENT_CLASS_TYPE(AppUpdate)
		CATAGORY(EventCategoryApplication)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "AppUpdate";
			return ss.str();
		}
	};

	class ENGINE_API AppRender :public EventAbstract
	{
	public:
		AppRender(){}
		EVENT_CLASS_TYPE(AppRender);
		CATAGORY(EventCategoryApplication)
		std::string getEvent() const override
		{
			std::stringstream ss;
			ss << "AppRender";
			return ss.str();
		}
	};
}