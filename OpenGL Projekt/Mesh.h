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

	void Initialize(std::vector<Vertex> vertices, std::vector<GLuint> indices);
	//void Initialize(Vertex* vertices, unsigned int numVertices, std::vector<GLuint>  indices);
	void Update(Vertex vertex, GLuint index);
	void Draw(int type = 0);

private:
	IndexedModel model;

	enum
	{
		POSITION_VB,
		INDEX_VB,
		NORMAL_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	//GLuint m_elementBufferObject;
	unsigned int m_drawCount;
};

