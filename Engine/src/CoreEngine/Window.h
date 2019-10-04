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
		unsigned int getWidth() const { return m_width; }
		unsigned int getHeight() const { return m_height; }
		Window(const char* title = "Guinea Engine", unsigned int width = 800, \
			unsigned int height = 600) :m_height(height), m_width(width), m_title(title)
		{
			if (!glfwInit())
			{
				CORE_ERROR("Can't initialize GLFW");
			}
			m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
			if (!m_window)
			{
				CORE_ERROR("Can't initialize window.");
				glfwTerminate();
			}
			else
			{
				run();
			}
		}
		void run()
		{
			glfwMakeContextCurrent(m_window);
			while (!glfwWindowShouldClose(m_window))
			{
				glClear(GL_COLOR_BUFFER_BIT);
				glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
				glfwSwapBuffers(m_window);
				glfwPollEvents();
			}
			glfwTerminate();
		}

	};
}