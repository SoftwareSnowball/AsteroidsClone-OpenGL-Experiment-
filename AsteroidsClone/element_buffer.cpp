#include "element_buffer.h"
#include <cassert>

ElementBuffer::ElementBuffer(const GLint * elements, GLsizei count)
	:count(count), id(0)
{
	glGenBuffers(1, &id);


	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLint), elements, GL_STATIC_DRAW);
	unbind();
}

ElementBuffer::~ElementBuffer()
{
	unbind();
	glDeleteBuffers(count * sizeof(GLint), &id);
}

void ElementBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void ElementBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
