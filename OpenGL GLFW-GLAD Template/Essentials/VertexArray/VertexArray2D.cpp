#include "VertexArray2D.h"

VertexArray2D::VertexArray2D()
{
	vertex = false;
	color = false;
	texture = false;
	normal = false;
}

void VertexArray2D::enableVertex(bool _Enabled)
{
	vertex = _Enabled;
}

void VertexArray2D::enableColor(bool _Enabled)
{
	color = _Enabled;
}

void VertexArray2D::enableTexture(bool _Enabled)
{
	texture = _Enabled;
}

void VertexArray2D::enableNormal(bool _Enabled)
{
	normal = _Enabled;
}

void VertexArray2D::draw(GLenum _Mode, GLenum _Type)
{
	
}
