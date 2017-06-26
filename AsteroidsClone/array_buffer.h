#pragma once

#include "externs.h"


#define ARRAYBUFFER_DOES_NOT_ALLOW_MULTIPLE_DATA_SETS 0

//Note that current implementation prohibits multiple data sets in one buffer
class ArrayBuffer
{
public:

	ArrayBuffer(const GLfloat* data, GLuint count, GLuint location, GLuint attributeCount);
	~ArrayBuffer();

	void bind() const;
	void unbind() const;

	inline GLuint getLocation() const { return location; }
	inline GLsizeiptr getSize() const { return sizeof(GLfloat) * count; }
	inline GLuint getCount() const { return count; }
	inline GLuint getAttribCount() const { return attributeCount; }


#if 0
	void setAttribPointer(int location, GLint attributeSize);
	void setAttribPointer(int location, GLint attributeSize, GLsizei stride);
#endif

private:

	GLuint location;
	GLuint count;
	GLuint attributeCount;
	GLuint id;

};
