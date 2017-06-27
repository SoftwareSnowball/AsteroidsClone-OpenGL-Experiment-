#include "callbacks.h"
#include <iostream>
#include "window.h"

void error_callback(int error, const char* description)
{
	std::cout << description << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* myWindow = (Window*)glfwGetWindowUserPointer(window);

	if (myWindow->keys[key] != 0 && action != 0)
	{
		myWindow->keys[key] = 2;
	}
	else if (action != 0)
	{
		myWindow->keys[key] = 1;
	}
	else
	{
		myWindow->keys[key] = 0;
	}

}