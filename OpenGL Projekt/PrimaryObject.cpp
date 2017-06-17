#include "PrimaryObject.h"

PrimaryObject::PrimaryObject() : shader()
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
	
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, NULL);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, NULL);
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
