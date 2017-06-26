#include "array_buffer.h"
#include <cassert>


ArrayBuffer::ArrayBuffer(const GLfloat* data, GLuint count, GLuint location, GLuint attributeCount)
	: id(0), count{ count }, location{ location }, attributeCount{ attributeCount }
{
	glGenBuffers(1, &id);

	GLsizeiptr size = getSize();

	bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	unbind();
}

ArrayBuffer::~ArrayBuffer()
{
	glDeleteBuffers(getSize(), &id);
}

void ArrayBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
} 

void ArrayBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

#if 0
void ArrayBuffer::setAttribPointer(int location, GLint attributeSize)
{
	setAttribPointer(location, attributeSize, attributeSize * sizeof(GLfloat));
}

void ArrayBuffer::setAttribPointer(int location, GLint attributeSize, GLsizei stride)
{
#if ARRAYBUFFER_DOES_NOT_ALLOW_MULTIPLE_DATA_SETS
	assert((count % (attributeSize) == 0));
#endif

	bind();
	glVertexAttribPointer(location, attributeSize, GL_FLOAT, GL_FALSE, stride, (GLvoid*)0);
	glEnableVertexAttribArray(location);
	unbind();

}

#endif
