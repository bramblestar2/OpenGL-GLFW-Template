#ifndef VERTEX_2D_H
#define VERTEX_2D_H

#include "../Vec2/Vec2.h"
#include "../Vec4/Vec4.h"

class Vertex2D
{
public:
	Vertex2D(const Vec2d _Position = Vec2d(), const Vec4d _Color = Vec4d(),
			 const Vec2d _Texture = Vec2d(), const Vec2d _Normal = Vec2d());

	Vec2d position;
	Vec4d color;
	Vec2d texture;
	Vec2d normal;
};

#endif