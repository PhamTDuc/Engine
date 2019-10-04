#pragma once
#include "window.h"
#include <iostream>

namespace Engine
{
	unsigned int Window::getWidth() const{return m_width;}
	unsigned int Window::getHeight() const{return m_height;}
	Window::Window(const char* title, unsigned int width,\
	unsigned int height):m_height(height),m_width(width),m_title(title)
	{
		if (!glfwInit())
		{
			CORE_ERROR("Can't initialize GLFW");
		}
		else
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		}

		m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
		if (!m_window)
		{
			CORE_ERROR("Can't initialize window.");
			glfwTerminate();
		}
		glfwSetFramebufferSizeCallback(m_window, Window::framebuffer_size_callback);
		glfwMakeContextCurrent(m_window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			CORE_ERROR("Can't initalize GLAD");
		}
	}

	void Window::run()
	{		
		while (!glfwWindowShouldClose(m_window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
			glfwSwapBuffers(m_window);
			glfwPollEvents();
		}
		glfwDestroyWindow(m_window);
	}

	void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		// make sure the viewport matches the new window dimensions; note that width and 
		// height will be significantly larger than specified on retina displays.
		glViewport(0, 0, width, height);

	}
}