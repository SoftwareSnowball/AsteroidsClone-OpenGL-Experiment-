#pragma once
#include "externs.h"
#include <vector>
#include <memory>
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

	GLuint getShaderID() const;

	GLsizei getRenderCount() const;


private:
	void activateBuffer(ArrayBuffer*);

	std::vector<std::shared_ptr<ArrayBuffer>> buffers;
	std::shared_ptr<ElementBuffer> elementBuffer;
	std::shared_ptr<Shader> shader;
	GLuint vaoID;


};