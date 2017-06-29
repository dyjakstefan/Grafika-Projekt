#pragma once
#include "Material.h"
#include "const.h"
#include <vector>
#include <queue>
class Options
{
public:
	~Options();

	static Options & GetInstance()
	{
		static Options options;
		return options;
	}
	Material& GetLineColor();
	Material& GetLightColor();
	void SetLineColor(Material material);
	void SetlightColor(Material material);
	int GetScreenWidth() { return screenWidth; }
	int GetScreenHeight() { return screenHeight; }
	void SetScreenWidth(int width) { screenWidth = width; }
	void SetScreenHeight(int height) { screenHeight = height; }
	Shape GetCurrentShape() { return currentShape; }
	void SetCurrentShape(Shape shape) { currentShape = shape; }
	void SetCurrRoute();
	std::queue<glm::vec4> GetCurrRoute() { return currRoute; }
	void Save();
	void Cancel();
	void Print(bool printing);

	bool printing;
	Material newLightColor;
	Material newLineColor;
	Shape newShape;
	bool newRoute;

private:
	Options();
	Options(const Options&);

	std::queue<glm::vec4> currRoute;
	std::queue<glm::vec4> route1;
	std::queue<glm::vec4> route2;
	std::queue<glm::vec4> route3;
	std::queue<glm::vec4> route4;

	int screenWidth;
	int screenHeight;
	
	Shape currentShape;
	Material lineColor;
	Material lightColor;
};

