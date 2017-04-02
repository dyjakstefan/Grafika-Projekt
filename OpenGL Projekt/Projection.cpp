#include "Projection.h"



Projection::Projection(float fov, float zNear, float zFar)
{
	m_fov = fov;
	m_zNear = zNear;
	m_zFar = zFar;
	m_aspect = (float)WIDTH / (float)HEIGHT;
}


Projection::~Projection()
{
}

glm::mat4 Projection::GetProjection() const
{
	glm::mat4 projection = glm::perspective(m_fov, m_aspect, m_zNear, m_zFar);
	return projection;
}
