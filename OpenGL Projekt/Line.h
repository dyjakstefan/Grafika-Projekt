#pragma once
#include "PrimaryObject.h"
#include <iostream>

class Line : public PrimaryObject
{
public:
	Line();
	~Line();

	void AddVertex(glm::vec3 vertex);

protected:
	
};

