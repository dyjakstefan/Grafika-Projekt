#pragma once
#include <vector>
#include "PrimaryObject.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

private:
	std::vector<PrimaryObject> objects;
	std::vector<PrimaryObject> objectsX;
	std::vector<PrimaryObject> objectsY;
	std::vector<PrimaryObject> objectsZ;
};

