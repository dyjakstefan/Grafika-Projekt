#pragma once
#include "PrimaryObject.h"
#include "Cube.h"
#include "Cylinder.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Draw(Camera view, Projection projection);
	void AddObject(PrimaryObject object);
	void UpdateObject();
private:
	std::vector<PrimaryObject> m_objects;
	float m_counter;
};

