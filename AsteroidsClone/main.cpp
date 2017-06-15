#include "externs.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;

void error_callback(int error, const char* description)
{
	printf(description);
}


std::string read_file(const char* path)
{
	std::ifstream reader(path);

	if (reader.fail())
	{
		std::cout << "Could not read file\n";
		return std::string();
	}



	std::string fileContents;
	std::string temp;


	while (!reader.eof())
	{
		std::getline(reader, temp);
		fileContents.append(temp);
		fileContents.append("\n");
	}



	reader.close();

	return fileContents;

}



int main()
{


	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		cout << "GLFW failed to initialize\n";
		system("PAUSE");

		return 0;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);


	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Asteroids", nullptr, nullptr);


	if (!window)
	{
		cout << "GLFW failed to create the window\n";
		system("PAUSE");
		return 0;
	}

	glfwMakeContextCurrent(window);
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_RENDERER) << std::endl;

	GLfloat vertices[] = { 
		-0.5f, -0.5f, 0.0f, 
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f };

	if (glewInit() != GLEW_OK) 
	{ 
		std::cout << "Failed to initialize GLEW" << std::endl; return -1;
	}

	glViewport(0, 0, 800, 600);

	GLuint VBO; 
	glGenBuffers(1, &VBO);


	std::string vertShader = read_file("shader.vert");
	std::string fragShader = read_file("shader.frag");


	//loading and compiling vertex shader
	GLuint vertexShader; 
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	const char* c_str = vertShader.c_str();
	glShaderSource(vertexShader, 1, &c_str, NULL); 
	glCompileShader(vertexShader);

	GLint success; GLchar infoLog[512]; 
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success) 
	{ 
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog); 
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl; 
	}

	//Loading and compiling fragment shader
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	c_str = fragShader.c_str();

	glShaderSource(fragmentShader, 1, &c_str, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//creating shader program
	GLuint shaderProgram; 
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader); 
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) 
	{ 
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "Shader link failed\n";
		std::cout << infoLog;
	}

	GLuint VAO; 
	glGenVertexArrays(1, &VAO);
		/* Render here */
	glBindVertexArray(VAO);
		// 0. Copy our vertices array in a buffer for OpenGL to use 
		glBindBuffer(GL_ARRAY_BUFFER, VBO); 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
		// 1. Then set the vertex attributes pointers 
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), ( GLvoid*)0);
		glEnableVertexAttribArray(0);
		// 2. Use our shader program when we want to render an object 
		glUseProgram(shaderProgram);
		// 3. Now draw the objec
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// 3. Then set our vertex attributes pointers 
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), ( GLvoid*)0); glEnableVertexAttribArray(0); 
		glEnableVertexAttribArray(0);
		//4. Unbind the VAO 
		glBindVertexArray(0);
	glBindVertexArray(0);





	while (!glfwWindowShouldClose(window))
	{

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram); 
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}