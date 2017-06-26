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

void Options::Save()
{
	currentShape = newShape;
	lineColor = newLineColor;
	lightColor = newLightColor;
}

void Options::Cancel()
{
	newShape = currentShape;
	newLightColor = lightColor;
	newLineColor = lineColor;
}

void Options::Print(bool printing)
{
	this->printing = printing;
}

Options::Options()
{
	lineColor = Material::redPlastic;

	lightColor.ambient = glm::vec3(0.05f, 0.05f, 0.05f);
	lightColor.diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
	lightColor.specular = glm::vec3(1.0f, 1.0f, 1.0f);
	lightColor.shininess = 0.0f;

	newLineColor = lineColor;
	newLightColor = lightColor;
	newShape = currentShape;
	currentShape = KOMIN;

	screenWidth = 800;
	screenHeight = 600;

	printing = false;
}


Options::~Options()
{
}
