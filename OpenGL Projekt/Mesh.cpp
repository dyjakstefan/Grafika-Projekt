#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBONorm);
	glDeleteBuffers(1, &VBOClr);
	glDeleteBuffers(1, &VBOuv);
}

void Mesh::Initialize()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBONorm);
	glDeleteBuffers(1, &VBOClr);
	glDeleteBuffers(1, &VBOuv);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glGenBuffers(1, &VBONorm);
	glGenBuffers(1, &VBOClr);
	glGenBuffers(1, &VBOuv);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO); 
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &(vertices[0]), GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	glBindBuffer(GL_ARRAY_BUFFER,VBONorm);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &(normals[0]), GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

	if (colors.size() != 0)
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBOClr);
		glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(glm::vec3), &(colors[0]), GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	}
	if (uvs.size() != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, VBOuv);
		glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_DYNAMIC_DRAW);

		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GL_FLOAT), (GLvoid*)0);
	}
	//glGenBuffers(1, &m_elementBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &(indices[0]), GL_DYNAMIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::Draw(int type)
{
	glBindVertexArray(VAO);

	if(type == 0)
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	else if (type == 1)
	{
		glLineWidth(3);
		glDrawElements(GL_LINE_STRIP, indices.size(), GL_UNSIGNED_INT, 0);
	}
	glBindVertexArray(0);
}

void Mesh::RecalculateNormals()
{
	normals.resize(vertices.size());

	for (size_t i = 0; i < indices.size() / 3; i++)
	{
		GLuint triangleIndex = i * 3;
		GLuint pointA = indices[triangleIndex];
		GLuint pointB = indices[triangleIndex + 1];
		GLuint pointC = indices[triangleIndex + 2];

		glm::vec3 normal = NormalFromIndices(pointA, pointB, pointC);

		normals[pointA] += normal;
		normals[pointB] += normal;
		normals[pointC] += normal;
	}

	for (size_t i = 0; i < normals.size(); i++)
	{
		normals[i] = glm::normalize(normals[i]);
	}
}

glm::vec3 Mesh::NormalFromIndices(GLuint a, GLuint b, GLuint c)
{
	glm::vec3 vertA = vertices[a];
	glm::vec3 vertB = vertices[b];
	glm::vec3 vertC = vertices[c];

	return glm::cross(vertB - vertA, vertC - vertA);
}

