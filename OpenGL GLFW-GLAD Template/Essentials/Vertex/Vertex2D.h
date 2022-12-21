#pragma once

#include "../Vec2/Vec2.h"
#include "../Vec3/Vec3.h"
#include "../Vec4/Vec4.h"

class Vertex2D
{
public:
	Vertex2D(const Vec2d _Position = Vec2d(), const Vec4d _Color = Vec4d(),
			 const Vec2d _Texture = Vec2d(), const Vec3d _Normal = Vec3d());

	Vec2d position;
	Vec4d color;
	Vec2d texture;
	Vec3d normal;
};