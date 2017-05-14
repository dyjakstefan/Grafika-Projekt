#include "Line.h"
#include "const.h"


Line::Line(const std::string & shaderName)
{
	/*vertices.push_back(Vertex(glm::vec3(0.0f, WS_Y_MAX, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)));
	indices.push_back(indices.size());*/

	material.ambient = glm::vec3(0.0, 0.0, 0.0);
	material.diffuse = glm::vec3(0.5, 0.0, 0.0);
	material.specular = glm::vec3(0.7, 0.6, 0.6);
	material.shininess = 25.0f;
	shader.Initialize("./res/" + shaderName);
	//mesh.Initialize(vertices, indices);
}


Line::~Line()
{
}

void Line::AddVertex(glm::vec3 vertex)
{
	vertices.push_back(Vertex(vertex , glm::vec3(0.0f, 1.0f, 0.0f)));
	indices.push_back(indices.size());
	mesh.Update(vertices[vertices.size()-1], indices.size());
}

void Line::Draw(Camera view, Projection projection)
{
	shader.Bind();
	shader.Update(transform, view, projection, material);
	mesh.Draw(1);
}


