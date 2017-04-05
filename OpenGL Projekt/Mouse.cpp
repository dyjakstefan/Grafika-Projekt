#include "Mouse.h"

Mouse::Mouse(double xpos, double ypos)
{
	m_xpos = xpos;
	m_ypos = ypos;
}

Mouse::~Mouse()
{
}

bool Mouse::IsPositionChanged(double xpos, double ypos)
{
	if(m_xpos != xpos)
		return true;
	if (m_ypos != ypos)
		return true;
}

glm::vec2 Mouse::UpdatePosition(double xpos, double ypos)
{
	GLfloat xoffset = xpos - m_xpos;
	GLfloat yoffset = m_ypos - ypos;

	m_xpos = xpos;
	m_ypos = ypos;

	return glm::vec2(xoffset, yoffset);
}

double Mouse::GetXpos()
{
	return m_xpos;
}

double Mouse::GetYpos()
{
	return m_ypos;
}
