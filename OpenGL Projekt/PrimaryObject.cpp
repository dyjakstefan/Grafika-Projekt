#include "PrimaryObject.h"



PrimaryObject::PrimaryObject()
{
}


PrimaryObject::~PrimaryObject()
{
}

void PrimaryObject::Draw(Camera view, Projection projection)
{
	shader.Bind();
	shader.Update(transform, view, projection, material);
	mesh.Draw();
}

Transform& PrimaryObject::Model()
{
	return transform;
}

void PrimaryObject::SetPos(const glm::vec3 & pos)
{
	transform.SetPos(pos);
}

void PrimaryObject::SetRot(const glm::vec3 & rot)
{
	transform.SetRot(rot);
}

void PrimaryObject::SetScale(const glm::vec3 & scale)
{
	transform.SetScale(scale);
}

void PrimaryObject::SetMaterial(const Material material)
{
	this->material.ambient = material.ambient;
	this->material.diffuse = material.diffuse;
	this->material.specular = material.specular;
	this->material.shininess = material.shininess;
}
