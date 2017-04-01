#include "Transform.h"


Transform::Transform(const glm::vec3& pos, const glm::vec3& rot , const glm::vec3& scale):
	m_pos(pos), m_rot(rot), m_scale(scale)
{
}


Transform::~Transform()
{
}

//inline glm::mat4 Transform::GetModel() const
//{
//	glm::mat4 posMatrix = glm::translate(m_pos);
//	glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
//	glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
//	glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));
//	glm::mat4 scaleMatrix = glm::scale(m_scale);
//
//	glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
//
//	return posMatrix * rotMatrix * scaleMatrix;
//}
