#include "Quad.h"



Quad::Quad()
{
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.0));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.0));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.0));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.0));

	mesh.uvs.push_back(glm::vec2(1, 1));
	mesh.uvs.push_back(glm::vec2(1, 0));
	mesh.uvs.push_back(glm::vec2(0, 0));
	mesh.uvs.push_back(glm::vec2(0, 1));

	mesh.indices.push_back(0);
	mesh.indices.push_back(2);
	mesh.indices.push_back(1);
	mesh.indices.push_back(0);
	mesh.indices.push_back(3);
	mesh.indices.push_back(2);

	mesh.RecalculateNormals();
	mesh.Initialize();
}


Quad::~Quad()
{
}
