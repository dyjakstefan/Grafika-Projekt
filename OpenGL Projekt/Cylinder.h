#pragma once
#include "PrimaryObject.h"

class Cylinder : public PrimaryObject
{
public:
	Cylinder(int points = 15);
	~Cylinder();
	void Update();
protected:

};

