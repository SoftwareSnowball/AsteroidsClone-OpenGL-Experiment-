#include "vertex_array.h"
#include <iostream>


VertexArray::VertexArray()
	:buffers(std::vector<std::shared_ptr<ArrayBuffer>>()), elementBuffer(nullptr)
{
	glGenVertexArrays(1, &vaoID);


}

VertexArray::~VertexArray()
{
	std::cout << "Destructor was called on Vertex Array\n";
	glDeleteVertexArrays(1, &vaoID);
}

void VertexArray::bind() const
{
	glBindVertexArray(vaoID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::addArrayBuffer(ArrayBuffer* buffer)
{

	buffers.push_back(std::shared_ptr<ArrayBuffer>(buffer));
	activateBuffer(buffer);

}

void VertexArray::setElementBuffer(ElementBuffer* buffer)
{

	bind();
	if (elementBuffer)
	{
		elementBuffer->unbind();
		//delete elementBuffer;
		elementBuffer = nullptr;
	}


	elementBuffer = std::shared_ptr<ElementBuffer>(buffer);

	buffer->bind();
	unbind();

}

void VertexArray::setShader(Shader * shaderInput)
{

	shader = std::shared_ptr<Shader>(shaderInput);

	bind();
	shader->setActive();
	unbind();


}

GLuint VertexArray::getShaderID() const
{
	if (!shader)
	{
		return 0;
	}

	return shader->getId();
}

GLsizei VertexArray::getRenderCount() const
{
	if (elementBuffer)
	{
		return elementBuffer->getCount();
	}
	else if (!buffers.empty())
	{
		return buffers[0]->getCount();
	}

	return 0;
}

void VertexArray::activateBuffer(ArrayBuffer* buffer)
{

	GLuint location = buffer->getLocation();
	GLint size = buffer->getSize();
	GLsizei stride = buffer->getAttribCount() * sizeof(GLfloat);


	bind();
	buffer->bind();

	glVertexAttribPointer(
		location,
		buffer->getAttribCount(), 
		GL_FLOAT, GL_FALSE,
		stride,
		(GLvoid*)0
	);

	glEnableVertexAttribArray(location);

	unbind();
}
