#pragma once
#include "GLEW\glew.h"

class Shader
{
public:
	Shader(const char * vertPath, const char * fragPath);
	~Shader();

	void setActive();
	inline GLuint getId() { return id; };

private:

	GLuint compileVertShader(const char* path);
	GLuint compileFragShader(const char* path);
	GLuint linkShaders(GLuint vert, GLuint frag);


	void clear();
	GLuint id;

};