#pragma once
#include "externs.h"


class ElementBuffer
{
public:

	ElementBuffer(const GLint* elements, GLsizei count);
	~ElementBuffer();

	void bind() const;
	void unbind() const;

	GLuint getCount() const { return count; }

private:
	GLsizei count;
	GLuint id;

};