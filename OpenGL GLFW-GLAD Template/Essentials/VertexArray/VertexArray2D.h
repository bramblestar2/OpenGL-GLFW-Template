#ifndef VERTEX_ARRAY_2D_H
#define VERTEX_ARRAY_2D_H
#include "../Vertex/Vertex2D.h"
#include <vector>

class VertexArray2D
{
public:
	VertexArray2D();

private:
	std::vector<Vertex2D> vertices;
};

#endif