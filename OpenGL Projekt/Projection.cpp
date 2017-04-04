#include "Projection.h"



Projection::Projection(GLfloat fov, GLfloat zNear, GLfloat zFar)
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
	glm::mat4 projection = glm::perspective(glm::radians(m_fov), m_aspect, m_zNear, m_zFar);
	return projection;
}
