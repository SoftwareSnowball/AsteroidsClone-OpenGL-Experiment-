#pragma once

#include "externs.h"
#include "math_lib.h"
#include "vertex_array.h"

class Renderer
{
public:

	Renderer();
	~Renderer();

	void clearBackBuffer();
	void draw();



private:

	vec4 clearColor;

};