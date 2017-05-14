#pragma once
#include "PrimaryObject.h"
class Cone :
	public PrimaryObject
{
public:
	Cone(int points = 15);
	~Cone();
protected:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

