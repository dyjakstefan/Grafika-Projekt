#pragma once
#include "PrimaryObject.h"

class Cylinder : public PrimaryObject
{
public:
	Cylinder(int points = 15);
	~Cylinder();
	void Draw(Camera view, Projection projection);
	void Update();
protected:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

