#pragma once
#include "Vertex.h"
#include "IndexedModel.h"
#include <GL/glew.h>
#include <vector>
class Mesh
{
public:
	//Mesh(Vertex* vertices, unsigned int numVertices, std::vector<GLuint>  indices);
	Mesh();
	~Mesh();

	void Initialize();
	void Draw(int type = 0);

	std::vector<glm::vec3> vertices;
	std::vector<GLuint> indices;
	std::vector<glm::vec3> normals;

private:
	GLuint VBO, EBO, VAO, VBONorm;
	unsigned int m_drawCount;
};

