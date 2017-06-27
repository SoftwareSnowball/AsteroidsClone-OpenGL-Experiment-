#pragma once
#include "externs.h"
#include "callbacks.h"



//This is a rough solution meant to only support one window at a time.
class Window
{
	friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
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

	bool isKeyPressed(int key);
	bool isKeyHeld(int key);

private:
	static bool glError;
	static bool isWindowInit;
	GLFWwindow* window;

	unsigned char keys[1024];

};
