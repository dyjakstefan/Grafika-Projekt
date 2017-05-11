#pragma once
#include "PrimaryObject.h"

class Cylinder : public PrimaryObject
{
public:
	Cylinder(int points = 15);
	~Cylinder();

protected:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

