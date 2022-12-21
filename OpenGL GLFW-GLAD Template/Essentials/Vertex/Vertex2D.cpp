#include "Vertex2D.h"

Vertex2D::Vertex2D(const Vec2d _Position, const Vec4d _Color, const Vec2d _Texture, const Vec2d _Normal)
{
	position = _Position;
	color = _Color;
	texture = _Texture;
	normal = _Normal;
}
