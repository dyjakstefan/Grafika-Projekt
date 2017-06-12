#pragma once
#include "PrimaryObject.h"
#include <iostream>

class Cube : public PrimaryObject
{
public:
	Cube(const std::string & shaderName = "basicShader");
	~Cube();
	void Draw(Camera view, Projection projection);
	void Update();
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
};

