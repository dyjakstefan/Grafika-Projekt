#include "Cylinder.h"



Cylinder::Cylinder(int points)
{
	mesh.vertices.resize(4 * points + 2);
	mesh.normals.resize(4 * points + 2);
	mesh.vertices[0] = glm::vec3(0.0, 0.5, 0.0);
	mesh.normals[0] = glm::vec3(0.0f, 1.0f, 0.0f);
	mesh.vertices[points + 1] = glm::vec3(0.0, -0.5, 0.0);
	mesh.normals[points + 1] = glm::vec3(0.0f, -1.0f, 0.0f);

	for (int i = 1; i <= points; i++)
	{
		GLfloat angle = 2 * glm::pi<float>() * i / points;
		//Top
		mesh.vertices[i] = glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5);
		mesh.normals[i] = glm::vec3(0.0f, 1.0f, 0.0f);
		mesh.vertices[i + points * 2 + 1] = glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5);
		mesh.normals[i + points * 2 + 1] = glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle));

		//Bottom
		mesh.vertices[i + points + 1] = glm::vec3(glm::cos(angle) * 0.5, -0.5, glm::sin(angle) * 0.5);
		mesh.normals[i + points + 1] = glm::vec3(0.0f, -1.0f, 0.0f);
		mesh.vertices[i + points * 3 + 1] = glm::vec3(glm::cos(angle) * 0.5, -0.5, glm::sin(angle) * 0.5);
		mesh.normals[i + points * 3 + 1] = glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle));
	}

	for (int j = 1; j < points; j++)
	{
		//Top
		mesh.indices.push_back(0);
		mesh.indices.push_back(j + 1);
		mesh.indices.push_back(j);

		//Bottom
		mesh.indices.push_back(points + 1);
		mesh.indices.push_back(points + 1 + j);
		mesh.indices.push_back(points + 2 + j);

		//Side
		mesh.indices.push_back(j + 1 + points * 2);
		mesh.indices.push_back(points * 3 + 2 + j);
		mesh.indices.push_back(points * 3 + 1 + j);

		mesh.indices.push_back(j + 1 + points * 2);
		mesh.indices.push_back(j + 1 + points * 2 + 1);
		mesh.indices.push_back(points * 3 + 2 + j);
	}

	//Top
	mesh.indices.push_back(0);
	mesh.indices.push_back(1);
	mesh.indices.push_back(points);

	//Bottom
	mesh.indices.push_back(points + 1);
	mesh.indices.push_back(points * 2 + 1);
	mesh.indices.push_back(points + 2);

	//Side

	mesh.indices.push_back(2 * points + 2);
	mesh.indices.push_back(2 + points * 3);
	mesh.indices.push_back(points * 4 + 1);

	mesh.indices.push_back(points * 3 + 1);
	mesh.indices.push_back(2 * points + 2);
	mesh.indices.push_back(points * 4 + 1);

	material.ambient = glm::vec3(0.25f, 0.25f, 0.25f);
	material.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
	material.specular = glm::vec3(0.774f, 0.774f, 0.774f);
	material.shininess = 60.0f;

	mesh.Initialize();
}


Cylinder::~Cylinder()
{
}

void Cylinder::Update()
{
	//shader.Initialize("./res/basicShader");
	mesh.Initialize();
}
