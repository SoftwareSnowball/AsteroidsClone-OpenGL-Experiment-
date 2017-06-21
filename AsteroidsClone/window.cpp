#include "window.h"
#include <cassert>

bool Window::isWindowInit = false;

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
