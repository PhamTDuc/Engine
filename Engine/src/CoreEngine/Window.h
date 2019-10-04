#pragma once
#include "CoreEngine/CoreHeader.h"
#include "CoreEngine/Logging.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace Engine
{
	class ENGINE_API Window
	{
	protected:
		const char* m_title;
		unsigned int m_width;
		unsigned int m_height;
		GLFWwindow* m_window;
	public:
		unsigned int getWidth() const;
		unsigned int getHeight() const;
		Window(const char* title = "Guinea Engine", unsigned int width = 800, \
			unsigned int height = 600);
		void run();
		void static framebuffer_size_callback(GLFWwindow* window, int width, int height);
	};
}