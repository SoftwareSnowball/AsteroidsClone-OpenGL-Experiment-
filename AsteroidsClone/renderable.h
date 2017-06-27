#pragma once

#include "GLEW\glew.h"

//Much efficient. So wow. Very draw call. This is gonna suck.
//Honestly, I'll learn how to draw more efficiently later.
//I just want to get asteroids done so I can move on to something else.
class Renderable
{
public:
	Renderable() = default;
	virtual ~Renderable() = default;

	virtual void bind() = 0;
	virtual GLuint getRenderCount() = 0;
	virtual void unbind() = 0;


};