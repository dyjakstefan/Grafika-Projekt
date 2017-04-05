#pragma once
#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex();
	Vertex(const glm::vec3& pos);
	~Vertex();

private:
	glm::vec3 m_pos;
};

