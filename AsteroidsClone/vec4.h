#pragma once

class vec4
{
public:
	vec4(float x, float y, float z, float w);
	~vec4() = default;

private:

	float x;
	float y;
	float z;
	float w;

};