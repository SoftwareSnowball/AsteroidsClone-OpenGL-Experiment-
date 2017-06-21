#pragma once
#include <iostream>
#include "externs.h"
#include "utils.h"

//This is a rough solution meant to only support one window at a time.
class Window
{

public:
	Window();
	Window(int width, int height);
	~Window();

	inline bool creationFailed() { return !window; };

	inline bool shouldClose() { return glfwWindowShouldClose(window); };
	inline GLFWwindow* getWinPointer() { return window; };
	inline void swapBuffers() { glfwSwapBuffers(window); };

private:
	static bool isWindowInit;
	GLFWwindow* window;

};
