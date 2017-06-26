#include "mat4.h"

mat4::mat4()
{
}

mat4::mat4(float * elementptr)
{

	for (int i = 0; i < 16; i++)
	{
		elements[i] = elementptr[i];
	}

}

mat4::~mat4()
{
}

mat4 & mat4::orthographic(float right, float left,
	float top, float bot, float near, float far)
{
	float rlDif = right - left;
	float tbDif = top - bot;
	float fnDif = far - near;

	float elements[] = { 2 / rlDif, 0, 0, 0,
				0, 2 / tbDif, 0, 0,
				0, 0, -2 / fnDif, 0,
				-(right + left) / rlDif,
				-(top + bot) / tbDif,
				-(far + near) / fnDif,
				1 
	};

	return mat4(elements);
}

mat4& mat4::perspective()
{
	return mat4();
}
