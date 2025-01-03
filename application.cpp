#include "application.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application(const std::string& title) 
{
	_title = title;
}

Application::~Application() 
{
	Application::Cleanup();
}

void Application::Run() 
{
	if (!Initialize()) 
	{
		return;
	}

	if (!Load())
	{
		return;
	}

	while (!glfwWindowShouldClose(_window))
	{
		glfwPollEvents();
		Update();
		Render();
	}
}

void Application::HandleResize(GLFWwindow* window, const int32_t width, const int32_t height) 
{
	Application* application = static_cast<Application*>(glfwGetWindowUserPointer(window));
	application->OnResize(width, height);
}

void Application::OnResize(const int32_t width, const int32_t height) 
{
	_width = width;
	_height = height;
}

void Application::Cleanup() 
{
	glfwTerminate();
}

bool Application::Initialize() 
{
	if (!glfwInit()) 
	{
		std::cout << "GLFW: Unable to initialize\n";
		return false;
	}

	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
	_width = static_cast<int32_t>(videoMode->width * 0.9f);
	_height = static_cast<int32_t>(videoMode->height * 0.9f);

	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	
	_window = glfwCreateWindow(_width, _height, _title.data(), nullptr, nullptr);

	if (_window == nullptr) 
	{
		std::cout << "GLFW: Unable to create window\n";
		Cleanup();
		return false;
	}

	const int32_t windowLeft = videoMode->width / 2 - _width / 2;
	const int32_t windowTop = videoMode->height / 2 - _height / 2;
	glfwSetWindowPos(_window, windowLeft, windowTop);

	return true;
}