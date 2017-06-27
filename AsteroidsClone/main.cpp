#include "externs.h"
#include <iostream>
#include <string>
#include "window.h"
#include "utils.h"
#include "shader.h"
#include "buffers.h"
#include "math_lib.h"

#include "entity.h"


int main()
{
	Window window;

	if (window.creationFailed())
	{
		std::cout << "Window creation failure.\n";
		system("PAUSE");
		return 0;
	}

#if 0
	GLfloat vertices[] = {
		-5, -5, 0,
		5, -5, 0,
		5, 5, 0,
		-5, 5, 0
	};

	GLint indices[] = {
		0,1,3,
		1,2,3
	};

	GLfloat color[] = {
		0.1, 0.0f, 0.8f, 1.0f,
		0.6, 0.0f, 0.8f, 1.0f,
		0.8, 0.0f, 0.8f, 1.0f,
		1.0, 0.0f, 0.8f, 1.0f
	};

	VertexArray VAO = VertexArray();
	Shader* shader = new Shader("shader.vert", "shader.frag");

	ArrayBuffer* vert = new ArrayBuffer(vertices, 3 * 4, 0, 3);
	ArrayBuffer* col = new ArrayBuffer(color, 4 * 4, 1, 4);
	ElementBuffer* el = new ElementBuffer(indices, 3 * 2);

	VAO.addArrayBuffer(vert);
	VAO.addArrayBuffer(col);
	VAO.setElementBuffer(el);

	VAO.setShader(shader);

#else

	Shader* shader = new Shader("shader.vert", "shader.frag");
	Entity* thing = new Entity(shader);

#endif

	mat4* view = mat4::orthographic(16, -16, 16, -16, 1, -1);

	GLint viewLocation = glGetUniformLocation(shader->getId(), "viewTransform"); 
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, view->getElements());


	int count = 0;

	mat4* scaler1 = (mat4::scaling(1.1, 1.1, 1.1));
	mat4* scaler2 = (mat4::scaling(1/1.1, 1 / 1.1, 1 / 1.1));

	thing->pushMatframe(*mat4::translation(12, 12, 0));


	while (!window.shouldClose())
	{

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//VAO.bind();
		//glDrawElements(GL_TRIANGLES, VAO.getRenderCount(), GL_UNSIGNED_INT, 0);
		//VAO.unbind();

		if (count < 50)
			thing->pushMatframe(*scaler1);
		else
		{
			thing->pushMatframe(*scaler2);
		}

		thing->bind();
		glDrawElements(GL_TRIANGLES, thing->getRenderCount(), GL_UNSIGNED_INT, 0);
		thing->unbind();

		window.update();

		count = (count + 1) % 100;


	}

	delete thing;
	glfwTerminate();

	return 0;
}