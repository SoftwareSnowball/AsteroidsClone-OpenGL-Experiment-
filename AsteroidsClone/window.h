#pragma once
#include "externs.h"

//This is a rough solution meant to only support one window at a time.
class Window
{

public:
	Window();
	Window(int width, int height);
	~Window();

	inline bool creationFailed() { return !window; }

	inline GLFWwindow* getWinPointer() { return window; };
	inline void swapBuffers() { glfwSwapBuffers(window); };

	bool shouldClose();
	void update();
	static bool checkGLErrors();

private:
	static bool glError;
	static bool isWindowInit;
	GLFWwindow* window;

};
