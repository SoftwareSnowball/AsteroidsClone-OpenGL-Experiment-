#pragma once
#include "externs.h"
#include <vector>
#include "array_buffer.h"
#include "element_buffer.h"
#include "shader.h"

class VertexArray
{
public:

	VertexArray();
	~VertexArray();

	void bind() const;
	void unbind() const;

	void addArrayBuffer(ArrayBuffer* buffer);
	void setElementBuffer(ElementBuffer* buffer);
	void setShader(Shader* shaderInput);

	GLsizei getRenderCount() const;


private:
	void activateBuffer(ArrayBuffer*);

	std::vector<ArrayBuffer*> buffers;
	ElementBuffer* elementBuffer;
	Shader* shader;
	GLuint vaoID;


};