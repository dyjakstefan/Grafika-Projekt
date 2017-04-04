#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "const.h"
class Projection
{
public:
	Projection(GLfloat fov = glm::radians(45.0f), GLfloat zNear = 0.1f, GLfloat zFar = 100.0f);
	~Projection();

	float GetFov() { return m_fov; }
	float GetAspect() { return m_aspect; }
	float GetZNear() { return m_zNear; }
	float GetZFar() { return m_zFar; }

	void SetFov(float fov) { m_fov = fov; }
	void SetZNear(float zNear) { m_zNear = zNear; }
	void SetZFar(float zFar) { m_zFar = zFar; }

	glm::mat4 GetProjection() const;

private:
	GLfloat m_fov;
	GLfloat m_aspect;
	GLfloat m_zNear;
	GLfloat m_zFar;
};

