#include "asset_manager.h"

AssetManager::AssetManager()
	:AssetManager("")
{
}

AssetManager::AssetManager(string assetRootDirectory)
	:m_assetRootDirectory{assetRootDirectory}
{
}

AssetManager::AssetManager(const char * assetRootDirectory)
	:AssetManager(string(assetRootDirectory))
{
}

GLuint AssetManager::compileVertShader(string name)
{
	string data = getFile(name);

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

	shaders.push_back(vertexShader);

	return vertexShader;
}

GLuint AssetManager::compileVertShader(const char * name)
{
	return compileVertShader(string(name));
}

GLuint AssetManager::compileFragShader(string name)
{
	string data = getFile(name);

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

	shaders.push_back(fragmentShader);
	return fragmentShader;
}

GLuint AssetManager::compileFragShader(const char * name)
{
	return compileFragShader(string(name));
}

void AssetManager::clearShaders()
{

	for (unsigned int i = 0; i < shaders.size(); i++)
	{
		glDeleteShader(shaders[i]);
	}

	shaders.clear();

}

void AssetManager::deleteShader(GLuint shaderid)
{

	//TODO

	std::cout << "Error. Function AssetManager::deleteShader(GLuint) not yet implemented\n";

}

GLuint AssetManager::compileShaderProgram(GLuint vertShader, GLuint fragShader)
{

	GLint success; GLchar infoLog[512];
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Shader link failed\n";
		std::cout << infoLog;
		return 0;
	}


	return shaderProgram;
}

string AssetManager::getFile(string name)
{
	return read_file(m_assetRootDirectory + name);
}
