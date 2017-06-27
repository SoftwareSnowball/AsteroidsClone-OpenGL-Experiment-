#pragma once
#include "vertex_array.h"
#include "math_lib.h"
#include <memory>
#include "renderable.h"

class Entity : public Renderable
{
public:

	Entity();
	~Entity();
	
	void update();
	void drawEntity();

	const vec3& getLocation() const;
	const mat4& getRotation() const;

	void setLocation(const vec3& newLocation);
	void setMatframe(const mat4& frame);
	void pushMatframe(const mat4& frame);
	void popMatframe(const mat4& frame);


	void bind() override;
	GLuint getRenderCount() override;
	void unbind() override;


protected:

	std::unique_ptr<VertexArray> VAO;
	vec3 location;
	vec3 velocity;
	mat4 matframe;
};