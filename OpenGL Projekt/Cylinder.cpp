#include "Cylinder.h"



Cylinder::Cylinder(int points)
{
	vertices.resize(4 * points + 2);
	vertices[0] = Vertex(glm::vec3(0.0, 0.5, 0.0), glm::vec3(0.0f, 1.0f, 0.0f));
	vertices[points + 1] = Vertex(glm::vec3(0.0, -0.5, 0.0), glm::vec3(0.0f, -1.0f, 0.0f));
	for (int i = 1; i <= points; i++)
	{
		GLfloat angle = 2 * glm::pi<float>() * i / points;
		//Top
		vertices[i] = Vertex(glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5), glm::vec3(0.0f, 1.0f, 0.0f));
		vertices[i + points * 2 + 1] = Vertex(glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5), glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle)));

		//Bottom
		vertices[i + points + 1] = Vertex(glm::vec3(glm::cos(angle) * 0.5, -0.5, glm::sin(angle) * 0.5), glm::vec3(0.0f, -1.0f, 0.0f));
		vertices[i + points * 3 + 1] = Vertex(glm::vec3(glm::cos(angle) * 0.5, -0.5, glm::sin(angle) * 0.5), glm::vec3(glm::cos(angle), 0.0f, glm::sin(angle)));
	}

	for (int j = 1; j < points; j++)
	{
		//Top
		indices.push_back(0);
		indices.push_back(j + 1);
		indices.push_back(j);

		//Bottom
		indices.push_back(points + 1);
		indices.push_back(points + 1 + j);
		indices.push_back(points + 2 + j);

		//Side
		indices.push_back(j + 1 + points * 2);
		indices.push_back(points * 3 + 2 + j);
		indices.push_back(points * 3 + 1 + j);

		indices.push_back(j + 1 + points * 2);
		indices.push_back(j + 1 + points * 2 + 1);
		indices.push_back(points * 3 + 2 + j);
	}

	//Top
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(points);

	//Bottom
	indices.push_back(points + 1);
	indices.push_back(points * 2 + 1);
	indices.push_back(points + 2);

	//Side

	indices.push_back(2 * points + 2);
	indices.push_back(2 + points * 3);
	indices.push_back(points * 4 + 1);

	indices.push_back(points * 3 + 1);
	indices.push_back(2 * points + 2);
	indices.push_back(points * 4 + 1);

	material.ambient = glm::vec3(0.25f, 0.25f, 0.25f);
	material.diffuse = glm::vec3(0.4f, 0.4f, 0.4f);
	material.specular = glm::vec3(0.774f, 0.774f, 0.774f);
	material.shininess = 60.0f;

	shader.Initialize("./res/basicShader");
	mesh.Initialize(vertices, indices);
}


Cylinder::~Cylinder()
{
}

void Cylinder::Draw(Camera view, Projection projection)
{
	shader.Bind();
	shader.Update(transform, view, projection, material);
	mesh.Draw();
}

void Cylinder::Update()
{
	shader.Initialize("./res/basicShader");
	mesh.Initialize(vertices, indices);
}
