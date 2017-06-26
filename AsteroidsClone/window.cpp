#include "window.h"
#include <iostream>
#include <cassert>
#include "utils.h"

bool Window::isWindowInit = false;
bool Window::glError = false;


Window::Window()
	:Window(800, 600)
{
}


Window::Window(int width, int height)
	:window{ nullptr }
{
	assert(!isWindowInit);

	isWindowInit = true;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		std::cout << "GLFW failed to initialize\n";
		system("PAUSE");
		return;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);



	window = glfwCreateWindow(width, height, "Asteroids", nullptr, nullptr);


	if (!window)
	{
		std::cout << "GLFW failed to create the window\n";
		system("PAUSE");
		return;
	}

	glfwMakeContextCurrent(window);
	std::cout << "Creating window using\n";
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_RENDERER) << std::endl;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
	}
	glViewport(0, 0, width, height);

	return;

}

Window::~Window()
{
	isWindowInit = false;
	glfwTerminate();
}

bool Window::shouldClose()
{

	if (glError)
	{
		system("PAUSE");
		return true;
	}

	if (glfwWindowShouldClose(window))
	{
		return true;
	}


	return false;
}

void Window::update()
{

	checkGLErrors();
	swapBuffers();
	glfwPollEvents();
}

bool Window::checkGLErrors()
{
	GLenum error = glGetError();

	if (error != GL_NO_ERROR)
	{
		std::cout << "OpenGL error: " << error << std::endl;
		glError = true;
	}

	return glError;
}
