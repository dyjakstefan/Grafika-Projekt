#pragma once
#include "PrimaryObject.h"
#include <iostream>

class Line : public PrimaryObject
{
public:
	Line(const std::string & shaderName = "lineShader");
	int i;
	~Line();

	void AddVertex(glm::vec3 vertex);
	void Draw(Camera view, Projection projection);

protected:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

