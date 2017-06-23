#include "externs.h"
#include <iostream>
#include <string>
#include "window.h"
#include "utils.h"
#include "asset_manager.h"

int main()
{

	Window window;

	if (window.creationFailed())
	{
		std::cout << "Window creation failure.\n";
		system("PAUSE");
		return 0;
	}

	GLfloat vertices[] = { 
		-0.5f, -0.5f, 0.0f, 
		0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	GLint indices[] = {
		0,1,3,
		1,2,3
	};

	AssetManager assetManager;

	GLuint vertexShader = assetManager.compileVertShader("shader.vert");
	GLuint fragmentShader = assetManager.compileFragShader("shader.frag");

	//creating shader program
	GLuint shaderProgram = assetManager.compileShaderProgram(vertexShader, fragmentShader);

	GLuint VBO;
	glGenBuffers(1, &VBO);

	GLuint EBO;
	glGenBuffers(1, &EBO);


	GLuint VAO; 
	glGenVertexArrays(1, &VAO); //
		/* Render here */
	glBindVertexArray(VAO);
		// 0. Copy our vertices array in a buffer for OpenGL to use 
		glBindBuffer(GL_ARRAY_BUFFER, VBO); 
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 

		//Copy into element buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		// 1. Then set the vertex attributes pointers 
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), ( GLvoid*)0);
		glEnableVertexAttribArray(0);
		// 2. Use our shader program when we want to render an object 
		glUseProgram(shaderProgram);
		// 3. Now draw the objec
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// 3. Then set our vertex attributes pointers 
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), ( GLvoid*)0);
		glEnableVertexAttribArray(0); 
		//4. Unbind the VAO 
	glBindVertexArray(0);





	while (!window.shouldClose())
	{

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram); 
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		/* Swap front and back buffers */
		window.swapBuffers();

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}