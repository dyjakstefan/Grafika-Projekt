#include "ObjectManager.h"



ObjectManager::ObjectManager()
{
	m_counter = 0.0f;
	Cube cube;
	Cube cube2;
	Cylinder cylinder(100);
	AddObject(cube);
	AddObject(cube2);
	AddObject(cylinder);
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Draw(Camera view, Projection projection)
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i].Draw(view, projection);
	}
}

void ObjectManager::AddObject(PrimaryObject object)
{
	m_objects.push_back(object);
}

void ObjectManager::UpdateObject()
{
	
}
