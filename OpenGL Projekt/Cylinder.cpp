#include "Cylinder.h"



Cylinder::Cylinder(int points)
{
	vertices.resize(4 * points + 2);
	vertices[0] = Vertex(glm::vec3(0.0, 0.5, 0.0));
	vertices[points + 1] = Vertex(glm::vec3(0.0, -0.5, 0.0));
	for (int i = 1; i <= points; i++)
	{
		GLfloat angle = 2 * glm::pi<float>() * i / points;
		//Top
		vertices[i] = Vertex(glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5));
		vertices[i + points * 2 + 1] = Vertex(glm::vec3(glm::cos(angle) * 0.5, 0.5, glm::sin(angle) * 0.5));

		//Bottom
		vertices[i + points + 1] = Vertex(glm::vec3(glm::cos(angle) * 0.5, -0.5, glm::sin(angle) * 0.5));
		vertices[i + points * 3 + 1] = Vertex(glm::vec3(glm::cos(angle) * 0.5, -0.5, glm::sin(angle) * 0.5));
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
	/*indices.push_back(1);
	indices.push_back(points + 2 );
	indices.push_back(points * 2 + 1);

	indices.push_back(points);
	indices.push_back(1);
	indices.push_back(points * 2 + 1);*/

	indices.push_back(2 * points + 2);
	indices.push_back(2 + points * 3);
	indices.push_back(points * 4 + 1);

	indices.push_back(points * 3 + 1);
	indices.push_back(2 * points + 2);
	indices.push_back(points * 4 + 1);

	m_shader.Initialize("./res/basicShader");
	m_mesh.Initialize(vertices, indices);
}


Cylinder::~Cylinder()
{
}
