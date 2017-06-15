#pragma once
#include "PrimaryObject.h"
#include <iostream>

class Line : public PrimaryObject
{
public:
	Line();
	void ZmianaKoloru(int i);
	int i;
	~Line();

	void AddVertex(glm::vec3 vertex);

protected:
	
};

