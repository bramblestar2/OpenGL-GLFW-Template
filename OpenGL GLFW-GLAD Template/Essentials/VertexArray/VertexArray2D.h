#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include <vector>
#include "../Vertex/Vertex2D.h"

//Order for drawing
//Position > Color > Texture > Normal
//A step is skipped if its disabled
//Everything is disabled by default
class VertexArray2D
{
public:
	VertexArray2D();

	void enableVertex(bool);
	void enableColor(bool);
	void enableTexture(bool);
	void enableNormal(bool);

	void draw(GLenum _Mode, GLenum _Type);
private:
	std::vector<Vertex2D> vertices;

	bool vertex, color, texture, normal;
};