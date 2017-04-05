#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"

class PrimaryObject
{
public:
	PrimaryObject();
	~PrimaryObject();

	void Draw(Camera view, Projection projection);
	Transform& Model();

	void SetPos(const glm::vec3& pos);
	void SetRot(const glm::vec3& rot);
	void SetScale(const glm::vec3& scale);

	glm::vec3 GetPos() { return m_transform.GetPos(); }
	glm::vec3 GetRot() { return m_transform.GetRot(); }
	glm::vec3 GetScale() { return m_transform.GetScale(); }

protected:
	Transform m_transform;
	Mesh m_mesh;
	Shader m_shader;
};

