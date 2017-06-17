#pragma once
#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"
#include "Material.h"

class PrimaryObject
{
public:
	PrimaryObject();
	~PrimaryObject();

	virtual void Draw(Camera view, Projection projection);
	Transform& Model();

	void SetPos(const glm::vec3& pos);
	void SetRot(const glm::vec3& rot);
	void SetScale(const glm::vec3& scale);
	void SetMaterial(const Material material);

	glm::vec3 GetPos() { return transform.GetPos(); }
	glm::vec3 GetRot() { return transform.GetRot(); }
	glm::vec3 GetScale() { return transform.GetScale(); }
	Material GetMaterial() { return material; }
	Material material;
	
protected:
	Transform transform;
	Mesh mesh;
	Shader shader;
};

