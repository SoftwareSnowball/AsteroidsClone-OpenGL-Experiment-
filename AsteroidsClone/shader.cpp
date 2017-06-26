#include "shader.h"

//Not sure if I want to leave this include here or move to header
//It's nice to not have it included with everything else but it should
//be guarded anyway, the rest of my code uses it, and it seems nicer to
//be able to look at the header and see all the libraries that something uses
#include "utils.h"

#include <iostream>


Shader::Shader(const char * vertPath, const char * fragPath)
{
	GLuint vert = compileVertShader(vertPath);
	GLuint frag = compileFragShader(fragPath);
	id = linkShaders(vert, frag);

}

Shader::~Shader()
{
	clear();
}

void Shader::setActive()
{
	glUseProgram(id);
}

GLuint Shader::compileVertShader(const char * path)
{
	std::string data = read_file(path);

	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	const char* c_str = data.c_str();
	glShaderSource(vertexShader, 1, &c_str, NULL);
	glCompileShader(vertexShader);

	GLint success; GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return 0;
	}

	return vertexShader;
}

GLuint Shader::compileFragShader(const char * path)
{
	std::string data = read_file(path);

	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const char* c_str = data.c_str();

	GLint success; GLchar infoLog[512];
	glShaderSource(fragmentShader, 1, &c_str, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return 0;
	}

	return fragmentShader;
}

GLuint Shader::linkShaders(GLuint vert, GLuint frag)
{
	GLint success; GLchar infoLog[512];
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vert);
	glAttachShader(shaderProgram, frag);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Shader link failed\n";
		std::cout << infoLog;
		return 0;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);

	return shaderProgram;
}

void Shader::clear()
{
	glDeleteProgram(id);
}
