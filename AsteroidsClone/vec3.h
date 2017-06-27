#pragma once

class vec3
{

public:

	vec3();
	vec3(float x, float y, float z);

	inline float getx() const { return x; }
	inline float gety() const { return y; }
	inline float getz() const { return z; }


private:
	float x;
	float y;
	float z;

};