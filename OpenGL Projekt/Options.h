#pragma once
#include "Material.h"

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

private:
	Options();
	Options(const Options&);

	int screenWidth;
	int screenHeight;

	Material lineColor;
	Material lightColor;
};

