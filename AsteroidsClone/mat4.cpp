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

void mat4::add(const mat4 & other)
{
	for (int i = 0; i < 16; i++)
	{
		elements[i] += other.elements[i];
	}
}

void mat4::sub(const mat4 & other)
{
	for (int i = 0; i < 16; i++)
	{
		elements[i] -= other.elements[i];
	}
}

mat4 mat4::mul(const mat4 & other)
{

	mat4 result;

	int i;
	int j;
	int k;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				result.getElementRef(i, j) += getElement(i, k) * other.getElement(k, j);
			}
		}
	}

	return result;

}

float mat4::determinant()
{
	return 0.0f;
}

mat4 mat4::transpose()
{
	return mat4();
}

mat4 mat4::invert()
{
	return mat4();
}

mat4 mat4::orthographic(float right, float left,
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

mat4 mat4::perspective()
{
	return mat4();
}

float & mat4::getElementRef(int row, int col)
{
	return elements[row + 4 * col];
}

float mat4::getElement(int row, int col) const
{
	
	
	return elements[row + 4 * col];

}
