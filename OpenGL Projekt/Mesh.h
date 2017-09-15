#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
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
	std::vector<glm::vec3> colors;
	std::vector<glm::vec2> uvs;
	void RecalculateNormals();
private:
	GLuint VBO, EBO, VAO, VBONorm;
	GLuint VBOuv, VBOClr;
	unsigned int m_drawCount;

	glm::vec3 NormalFromIndices(GLuint a, GLuint b, GLuint c);
};

