#include "Options.h"



Material& Options::GetLineColor()
{
	return lineColor;
}

Material& Options::GetLightColor()
{
	return lightColor;
}

void Options::SetLineColor(Material material)
{
	lineColor.ambient = material.ambient;
	lineColor.diffuse = material.diffuse;
	lineColor.specular = material.specular;
	lineColor.shininess = material.shininess;
}

void Options::SetlightColor(Material material)
{
	lightColor.ambient = material.ambient;
	lightColor.diffuse = material.diffuse;
	lightColor.specular = material.specular;
	lightColor.shininess = material.shininess;
}

Options::Options()
{
	lineColor.ambient = glm::vec3(0.0, 0.0, 0.0);
	lineColor.diffuse = glm::vec3(0.5, 0.0, 0.0);
	lineColor.specular = glm::vec3(0.7, 0.6, 0.6);
	lineColor.shininess = 25.0f;

	lightColor.ambient = glm::vec3(0.05f, 0.05f, 0.05f);
	lightColor.diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
	lightColor.specular = glm::vec3(1.0f, 1.0f, 1.0f);
	lightColor.shininess = 0.0f;
}


Options::~Options()
{
}
