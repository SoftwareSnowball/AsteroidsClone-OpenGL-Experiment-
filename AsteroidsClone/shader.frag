#version 330 core
in vec4 vertexColor;
out vec4 color;


void main() 
{ 
	//color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	color = vertexColor;
}