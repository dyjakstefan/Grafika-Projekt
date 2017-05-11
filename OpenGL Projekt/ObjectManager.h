#pragma once
#include <vector>
#include "Cube.h"
#include "Cylinder.h"
#include "Projection.h"
#include "Camera.h"
#include "SDL_events.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Draw(Camera view, Projection projection);
	void Events(const Uint8* currentKeyStates, GLfloat deltaTime);
private:
	std::vector<PrimaryObject*> objectsToDraw;
	std::vector<PrimaryObject*> objectsX;
	std::vector<PrimaryObject*> objectsY;
	std::vector<PrimaryObject*> objectsZ;

	Cylinder prowadnica_pionowa_lewa, prowadnica_pionowa_prawa;
	Cylinder prowadnica_pozioma_lewa, prowadnica_pozioma_prawa;
	Cylinder mala_prowadnica_pozioma1, mala_prowadnica_pozioma2;


	Cube stol, podloga, lozysko_poziome_lewe, lozysko_poziome_prawe, glowica;
	Cube bottom1, bottom2, bottom3, bottom4;
	Cube middle1, middle2, middle3, middle4, middle5, middle6, middle7, middle8;
	Cube ziemia;

	GLfloat movementSpeed;
};

