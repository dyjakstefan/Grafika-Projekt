#include "Vertex.h"

Vertex::Vertex()
{
}

Vertex::Vertex(const glm::vec3& pos, const glm::vec3& normal)
{
	this->pos = pos;
	this->normal = normal;
}


Vertex::~Vertex()
{
}
