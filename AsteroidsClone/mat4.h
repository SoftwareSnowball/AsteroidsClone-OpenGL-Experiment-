#pragma once

#include "vec4.h"
#include "vec3.h"

class mat4
{
public:
	mat4();
	mat4(float* elementptr);
	~mat4();

	void add(const mat4& other);
	void sub(const mat4& other);
	mat4 mul(const mat4& other);

	float determinant();

	mat4 transpose();
	mat4 invert();

	static mat4 orthographic(float right, float left, float top, float bot, float near, float far);
	static mat4 perspective();

	static mat4 scaling(float x, float y, float z);
	static mat4 translation(float x, float y, float z);
	static mat4 translation(const vec3&);
	static mat4 rotation();

	inline const float* getElements() { return elements; }

	float& getElementRef(int row, int col);
	float getElement(int row, int col) const;

private:

	

	float elements[4 * 4];



};