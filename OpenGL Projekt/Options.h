#pragma once
#include "Material.h"
#include "const.h"
#include <vector>
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
	void Save();
	void Cancel();
	void Print(bool printing);

	bool printing;
	Material newLightColor;
	Material newLineColor;
	Shape newShape;
private:
	Options();
	Options(const Options&);

	int screenWidth;
	int screenHeight;
	
	Shape currentShape;
	Material lineColor;
	Material lightColor;
};

