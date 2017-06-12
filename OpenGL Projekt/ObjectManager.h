#pragma once
#include <vector>
#include <queue>
#include "Cube.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Projection.h"
#include "Camera.h"
#include "SDL_events.h"
#include "Line.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Draw(Camera view, Projection projection);
	void Events(const Uint8* currentKeyStates, GLfloat deltaTime);
	void MoveByRoute(GLfloat deltaTime);
	void PrintCubes();
	void SetRoute(std::queue<glm::vec3> route);
	void AddCube();
private:
	

	std::vector<PrimaryObject*> objectsToDraw;
	std::vector<PrimaryObject*> objectsX;
	std::vector<PrimaryObject*> objectsY;
	std::vector<PrimaryObject*> objectsZ;
	std::vector<Cube> cubes;
	std::vector<glm::vec3> route;
	std::queue<glm::vec3> routeQ;
	glm::vec3 headPosition;

	Cylinder prowadnica_pionowa_lewa, prowadnica_pionowa_prawa;
	Cylinder prowadnica_pozioma_lewa, prowadnica_pozioma_prawa;
	Cylinder mala_prowadnica_pozioma1, mala_prowadnica_pozioma2;
	Cylinder czesc_glowicy;

	Cube stol, podloga, lozysko_poziome_lewe, lozysko_poziome_prawe, glowica;
	Cube bottom1, bottom2, bottom3, bottom4;
	Cube top1, top2, top3, top4;
	Cube middle1, middle2, middle3, middle4, middle5, middle6, middle7, middle8;
	Cube ziemia;

	Cone iglica;

	bool lineMode;
	float cubeSize;

	Line linia;

	GLfloat movementSpeed;

	void MoveX(float velocity);
	void MoveY(float velocity);
	void MoveZ(float velocity);
};

