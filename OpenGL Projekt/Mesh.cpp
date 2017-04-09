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

void Mesh::Initialize(std::vector<Vertex> vertices, std::vector<GLuint>  indices)
{
	m_drawCount = indices.size();
	
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers); 
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]); 
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW); 

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//glGenBuffers(1, &m_elementBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &(indices[0]), GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);

	//glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glDrawElementsBaseVertex(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0, 0);

	glBindVertexArray(0);
}

