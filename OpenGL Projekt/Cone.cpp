#include "Cone.h"



Cone::Cone(int points)
{
	mesh.vertices.resize(3 * points + 2);
	mesh.normals.resize(3 * points + 2);
	mesh.vertices[0] = glm::vec3(0.0, 0.5, 0.0);
	mesh.normals[0] = glm::vec3(0.0f, 1.0f, 0.0f);
	//vertices[points + 1] = Vertex(glm::vec3(0.0, -0.5, 0.0), glm::vec3(0.0f, -1.0f, 0.0f));
	for (int i = 1; i <= points; i++)
	{
		GLfloat angle = 2 * glm::pi<float>() * i / points;
		//Top
		mesh.vertices[i] = glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5);
		mesh.normals[i] = glm::vec3(0.0f, 1.0f, 0.0f);
		mesh.vertices[i + points * 2] = glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5);
		mesh.normals[i + points * 2] = glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle));

		//Bottom
		mesh.vertices[i + points] = glm::vec3(0.0, -0.5, 0.0);
		mesh.normals[i + points] = glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle));

	}

	for (int j = 1; j < points; j++)
	{
		//Top
		mesh.indices.push_back(0);
		mesh.indices.push_back(j + 1);
		mesh.indices.push_back(j);

		//Side
		mesh.indices.push_back(j + points * 2);
		mesh.indices.push_back(j + points * 2 + 1);
		mesh.indices.push_back(points + 1 + j);
	}

	//Top
	mesh.indices.push_back(0);
	mesh.indices.push_back(1);
	mesh.indices.push_back(points);

	//Side
	mesh.indices.push_back(points * 2);
	mesh.indices.push_back(3 * points);
	mesh.indices.push_back(points * 2 + 1);

	material.ambient = glm::vec3(0.25f, 0.25f, 0.25f);
	material.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
	material.specular = glm::vec3(0.774f, 0.774f, 0.774f);
	material.shininess = 60.0f;

	mesh.RecalculateNormals();
	mesh.Initialize();
}


Cone::~Cone()
{
}
