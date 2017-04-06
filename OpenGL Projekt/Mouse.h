#pragma once
#include "const.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
class Mouse
{
public:
	Mouse(double xpos, double ypos);
	~Mouse();

	bool IsPositionChanged(double xpos, double ypos);
	glm::vec2 UpdatePosition(double xpos, double ypos);
	void SetPosX(double x);
	void SetPosY(double y);

	double GetXpos();
	double GetYpos();

private:
	double m_xpos;
	double m_ypos;
};

