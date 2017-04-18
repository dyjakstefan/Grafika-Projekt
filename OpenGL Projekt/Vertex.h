#pragma once
#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex();
	Vertex(const glm::vec3& pos, const glm::vec3& normal);
	~Vertex();

	glm::vec3* GetPos() { return &pos; }
	glm::vec3* GetNormal() { return &normal; }

private:
	glm::vec3 pos;
	glm::vec3 normal;
};

