#pragma once
#include "PrimaryObject.h"

class Cube : public PrimaryObject
{
public:
	Cube();
	~Cube();

private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

