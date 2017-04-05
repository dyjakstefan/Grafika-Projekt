#include "Cube.h"



Cube::Cube()
{
	std::vector<Vertex> vert = {
		//Front
		Vertex(glm::vec3(0.5, 0.5, 0.5)),
		Vertex(glm::vec3(0.5, -0.5, 0.5)),
		Vertex(glm::vec3(-0.5, -0.5, 0.5)),
		Vertex(glm::vec3(-0.5, 0.5, 0.5)),
		//Back
		Vertex(glm::vec3(0.5, 0.5, -0.5)),
		Vertex(glm::vec3(0.5, -0.5, -0.5)),
		Vertex(glm::vec3(-0.5, -0.5, -0.5)),
		Vertex(glm::vec3(-0.5, 0.5, -0.5)),
		//Top
		Vertex(glm::vec3(0.5, 0.5, 0.5)),
		Vertex(glm::vec3(-0.5, 0.5, 0.5)),
		Vertex(glm::vec3(0.5, 0.5, -0.5)),
		Vertex(glm::vec3(-0.5, 0.5, -0.5)),
		//Bottom
		Vertex(glm::vec3(0.5, -0.5, 0.5)),
		Vertex(glm::vec3(-0.5, -0.5, 0.5)),
		Vertex(glm::vec3(0.5, -0.5, -0.5)),
		Vertex(glm::vec3(-0.5, -0.5, -0.5)),
		//Left
		Vertex(glm::vec3(-0.5, 0.5, 0.5)),
		Vertex(glm::vec3(-0.5, -0.5, 0.5)),
		Vertex(glm::vec3(-0.5, -0.5, -0.5)),
		Vertex(glm::vec3(-0.5, 0.5, -0.5)),
		//Right
		Vertex(glm::vec3(0.5, 0.5, 0.5)),
		Vertex(glm::vec3(0.5, -0.5, 0.5)),
		Vertex(glm::vec3(0.5, -0.5, -0.5)),
		Vertex(glm::vec3(0.5, 0.5, -0.5)),
	};

	std::vector<GLuint> ind = {
		//Front
		0, 3, 2,
		0, 2, 1,
		//Back
		5, 6, 7,
		5, 7, 4,
		//Top
		10, 11, 9,
		10, 9, 8,
		//Bottom
		12, 13, 15,
		12, 15, 14,
		//Left
		16, 19, 18,
		16, 18, 17,
		//Right
		23, 20, 21,
		23, 21, 22,
	};

	vertices = vert;
	indices = ind;

	m_shader.Initialize("./res/basicShader");
	m_mesh.Initialize(vertices, indices);
}


Cube::~Cube()
{
}
