#include "Mesh.h"
#include <iostream>


//Mesh::Mesh(Vertex* vertices, unsigned int numVertices, std::vector<GLuint>  indices)
//{
//  //m_drawCount = numVertices;
//  m_drawCount = indices.size();
//  glGenVertexArrays(1, &m_vertexArrayObject);
//  glBindVertexArray(m_vertexArrayObject);
//
//  glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
//  glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
//  glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
//
//  glGenBuffers(1, &m_elementBufferObject);
//  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_elementBufferObject);
//  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &(indices[0]), GL_STATIC_DRAW);
//
//  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
//  glEnableVertexAttribArray(0);
//
//  glBindVertexArray(0);
//}

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
	glDeleteVertexArrays(1, &m_vertexArrayObject);

}

void Mesh::Initialize(std::vector<Vertex> vertices, std::vector<GLuint> indices)
{
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		model.positions.push_back(*vertices[i].GetPos());
		model.normals.push_back(*vertices[i].GetNormal());
	}

	for (unsigned int i = 0; i < indices.size(); i++)
		model.indices.push_back(indices[i]);

	m_drawCount = indices.size();
	
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers); 
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); 
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(glm::vec3), model.positions.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(glm::vec3), model.normals.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//glGenBuffers(1, &m_elementBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(GLuint), &(model.indices[0]), GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);

	//glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glDrawElementsBaseVertex(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0, 0);

	glBindVertexArray(0);
	/*glBindVertexArray(m_lightVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);*/
}

