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
	case 2: currRoute = route3;
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
	int z = 1;
	int y = 1;

	route2.push(glm::vec4(-4, 0, 0, 0));
	route2.push(glm::vec4(0, 0, -4, 0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			x *= -1;
			if (j == 0)
			{
				route2.push(glm::vec4(0, 0, 5 * x, 1));
			}
			else
			{
				route2.push(glm::vec4(0, 0, 4 * x, 1));
			}
			if (j < 4)
			{
				route2.push(glm::vec4(1, 0, 0, 1));
			}
		}

		route2.push(glm::vec4(0, 1, 0, 1));
		route2.push(glm::vec4(-3, 0, 0, 0));
		route2.push(glm::vec4(-1, 0, 0, 1));
		route2.push(glm::vec4(0, 0, -3, 0));
		route2.push(glm::vec4(0, 0, -1, 1));
		route2.push(glm::vec4(3, 0, 0, 0));
		route2.push(glm::vec4(1, 0, 0, 1));
		route2.push(glm::vec4(-4, 0, 0, 0));
		route2.push(glm::vec4(0, 1, -1, 0));
		x = -1;
	}

	route1.push(glm::vec4(0, 0, 5, 1));

	x = -1;
	for (int i = 0; i < 4; i++)
	{
		route1.push(glm::vec4(1, 0, 0, 1));
		route1.push(glm::vec4(0, 0, x * 4, 1));
		x *= -1;
	}
	for (int j = 0; j < 5; j++)
	{
		route1.push(glm::vec4(0, 1, 0, 1));
		route1.push(glm::vec4(0, 0, -4, 1));
		route1.push(glm::vec4(-4, 0, 0, 1));
		route1.push(glm::vec4(0, 0, 4, 1));
		route1.push(glm::vec4(4, 0, 0, 1));
	}

	x = 1;
	z = 1;
	route3.push(glm::vec4(-4, 0, 0, 0));
	route3.push(glm::vec4(0, 0, 4, 0));
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 7; j > 2*i; j--)
		{
			x *= -1;
			if (j == 7)
			{
				route3.push(glm::vec4(0, 0, (7 - 2 * i) * x, 1));
			}
			else
			{
				route3.push(glm::vec4(0, 0, (6 - 2 * i) * x, 1));
			}
			if (j > (2 * i + 1))
			{
				route3.push(glm::vec4(1 * z, 0, 0, 1));
			}
		}
		z *= -1;
		route3.push(glm::vec4(z, 0, 0, 0));
		route3.push(glm::vec4(0, 1, 0, 0));
	}
}


Options::~Options()
{
}
