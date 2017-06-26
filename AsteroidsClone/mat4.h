#pragma once

#include "vec4.h"

class mat4
{
public:
	mat4();
	mat4(float* elementptr);
	~mat4();

	static mat4& orthographic(float right, float left, float top, float bot, float near, float far);
	static mat4& perspective();

	static mat4 scaling(float x, float y, float z);
	static mat4 translation(float x, float y, float z);
	static mat4 rotation();

	inline float* getElements() { return elements; }

private:

	float elements[4 * 4];



};