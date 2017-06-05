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

private:
	Options();
	Options(const Options&);

	Material lineColor;
	Material lightColor;
};

