#pragma once
#include "PrimaryObject.h"

class Cone :
	public PrimaryObject
{
public:
	Cone(int points = 15);
	~Cone();
	void Draw(Camera view, Projection projection);

protected:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

