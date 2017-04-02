#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "const.h"
class Projection
{
public:
	Projection(float fov = glm::radians(45.0f), float zNear = 0.1f, float zFar = 100.0f);
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
	float m_fov;
	float m_aspect;
	float m_zNear;
	float m_zFar;
};

