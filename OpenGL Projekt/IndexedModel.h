#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

class IndexedModel
{
public:
	IndexedModel();
	~IndexedModel();

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;

	void CalcNormals();
};

