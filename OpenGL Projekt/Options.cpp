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

void Options::SetCurrRoute()
{
	switch (currentShape)
	{
	case 0:	currRoute = route1;
		break;
	case 1: currRoute = route2;
		break;
	default: currRoute = route1;
		break;
	}
}

void Options::Save()
{
	//currentShape = newShape;
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
	newRoute = true;
	SetCurrRoute();
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
	newRoute = false;
	
	int x = -1;
	route2.push(glm::vec3(0, 0, 5));

	for (int i = 0; i < 4; i++)
	{
		route2.push(glm::vec3(1, 0, 0));
		route2.push(glm::vec3(0, 0, x * 4));
		x *= -1;
	}
	for (int j = 0; j < 5; j++)
	{
		route2.push(glm::vec3(0, 3, 0));
		route2.push(glm::vec3(0, 0, -4));
		route2.push(glm::vec3(-4, 0, 0));
		route2.push(glm::vec3(0, 0, 4));
		route2.push(glm::vec3(4, 0, 0));
	}

	route1.push(glm::vec3(0, 0, 5));

	x = -1;
	for (int i = 0; i < 4; i++)
	{
		route1.push(glm::vec3(1, 0, 0));
		route1.push(glm::vec3(0, 0, x * 4));
		x *= -1;
	}
	for (int j = 0; j < 5; j++)
	{
		route1.push(glm::vec3(0, 1, 0));
		route1.push(glm::vec3(0, 0, -4));
		route1.push(glm::vec3(-4, 0, 0));
		route1.push(glm::vec3(0, 0, 4));
		route1.push(glm::vec3(4, 0, 0));
	}

}


Options::~Options()
{
}
