#include "PrimaryObject.h"



PrimaryObject::PrimaryObject()
{
}


PrimaryObject::~PrimaryObject()
{
}

void PrimaryObject::Draw(Camera view, Projection projection)
{
	m_shader.Bind();
	m_shader.Update(m_transform, view, projection, material);
	m_mesh.Draw();
}

Transform& PrimaryObject::Model()
{
	return m_transform;
}

void PrimaryObject::SetPos(const glm::vec3 & pos)
{
	m_transform.SetPos(pos);
}

void PrimaryObject::SetRot(const glm::vec3 & rot)
{
	m_transform.SetRot(rot);
}

void PrimaryObject::SetScale(const glm::vec3 & scale)
{
	m_transform.SetScale(scale);
}
