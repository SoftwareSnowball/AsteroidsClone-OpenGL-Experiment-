#include "entity.h"

Entity::Entity()
{
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

	VAO = std::unique_ptr<VertexArray>();
	Shader* shader = new Shader("shader.vert", "shader.frag");

	ArrayBuffer* vert = new ArrayBuffer(vertices, 3 * 4, 0, 3);
	ArrayBuffer* col = new ArrayBuffer(color, 4 * 4, 1, 4);
	ElementBuffer* el = new ElementBuffer(indices, 3 * 2);

	VAO->addArrayBuffer(vert);
	VAO->addArrayBuffer(col);
	VAO->setElementBuffer(el);

	VAO->setShader(shader);


}

Entity::~Entity()
{
}

void Entity::update()
{
}

void Entity::drawEntity()
{
}

const vec3& Entity::getLocation() const
{
	return location;
}

const mat4& Entity::getRotation() const
{
	return matframe;
}

void Entity::setLocation(const vec3& newLocation)
{
	location = newLocation;
}

void Entity::setMatframe(const mat4& frame)
{
	matframe = frame;
}

void Entity::pushMatframe(const mat4& frame)
{
	matframe = matframe.mul(frame);
}

void Entity::popMatframe(const mat4 & frame)
{
}

void Entity::bind()
{
	if (!VAO)
	{
		return;
	}

	
	VAO->bind();

}

GLuint Entity::getRenderCount()
{
	if (!VAO)
	{
		return 0;
	}
	return VAO->getRenderCount();
}

void Entity::unbind()
{
	if (!VAO)
	{
		return;
	}

	VAO->unbind();

}
