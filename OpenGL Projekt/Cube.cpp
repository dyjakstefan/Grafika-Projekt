#include "Cube.h"



Cube::Cube()
{
	//front
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.5));

	//back
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, -0.5));

	//right
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, -0.5));

	//left
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.5));

	//up
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, 0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(0.5, 0.5, 0.5));

	//bottom
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, 0.5));
	mesh.vertices.push_back(glm::vec3(-0.5, -0.5, -0.5));
	mesh.vertices.push_back(glm::vec3(0.5, -0.5, -0.5));

	for (size_t i = 0; i < 6; i++)
	{
		mesh.indices.push_back(i * 4);
		mesh.indices.push_back(i * 4 + 1);
		mesh.indices.push_back(i * 4 + 2);

		mesh.indices.push_back(i * 4);
		mesh.indices.push_back(i * 4 + 2);
		mesh.indices.push_back(i * 4 + 3);
	}
	mesh.normals.resize(24);
	for (int i = 0; i < 4; i++)
	{
		mesh.normals[i] = glm::vec3(0.0f, 0.0f, 1.0f);
		mesh.normals[i + 4] = glm::vec3(0.0f, 0.0f, -1.0f);
		mesh.normals[i + 4 * 2] = glm::vec3(1.0f, 0.0f, 0.0f);
		mesh.normals[i + 4 * 3] = glm::vec3(-1.0f, 0.0f, 1.0f);
		mesh.normals[i + 4 * 4] = glm::vec3(0.0f, 1.0f, 0.0f);
		mesh.normals[i + 4 * 5] = glm::vec3(0.0f, -1.0f, 0.0f);
	}

	material.ambient = glm::vec3(0.0f, 0.1f, 0.06f);
	material.diffuse = glm::vec3(0.0f, 0.50980392f, 0.50980392f);
	material.specular = glm::vec3(0.50196078f, 0.50196078f, 0.50196078f);
	material.shininess = 25.0f;

	mesh.Initialize();
}


Cube::~Cube()
{
}


void Cube::Update()
{
	//shader.Initialize();
	mesh.Initialize();
}

void Cube::AddUvs()
{
}
