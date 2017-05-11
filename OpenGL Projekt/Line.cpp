#include "Line.h"



Line::Line(const std::string & shaderName)
{
	material.ambient = glm::vec3(0.0f, 0.1f, 0.06f);
	material.diffuse = glm::vec3(0.0f, 0.50980392f, 0.50980392f);
	material.specular = glm::vec3(0.50196078f, 0.50196078f, 0.50196078f);
	material.shininess = 25.0f;
	shader.Initialize("./res/" + shaderName);
}


Line::~Line()
{
}

void Line::AddVertex(glm::vec3 vertex)
{
	vertices.push_back(Vertex(vertex, glm::vec3(0.0f, 1.0f, 0.0f)));
	indices.push_back(indices.size());
	mesh.Initialize(vertices, indices);
}

void Line::Draw(Camera view, Projection projection)
{
	shader.Bind();
	shader.Update(transform, view, projection, material);
	mesh.Draw(1);
}
