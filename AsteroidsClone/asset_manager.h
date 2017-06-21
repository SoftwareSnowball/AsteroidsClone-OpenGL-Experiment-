#pragma once
#include "utils.h"
#include "externs.h"

#include <string>
#include <vector>
using std::string;
using std::vector;


//This is part of Operation Get This Rubbish Out Of Main.


class AssetManager
{
public:
	AssetManager();
	AssetManager(string assetRootDirectory);
	AssetManager(const char* assetRootDirectory);

	GLuint compileVertShader(string name);
	GLuint compileVertShader(const char* name);

	GLuint compileFragShader(string name);
	GLuint compileFragShader(const char* name);

	void clearShaders();
	void deleteShader(GLuint shaderid);

	GLuint compileShaderProgram(GLuint vertShader, GLuint fragShader); //Probably really limited but it should be enough for this program

	void writeErrorLogFile();


private:

	vector<GLuint> shaders;

	string getFile(string name);
	string m_assetRootDirectory;

};