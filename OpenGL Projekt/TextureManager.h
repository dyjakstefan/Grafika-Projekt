#pragma once
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include "stb_image.h"

class TextureManager
{
public:
	static TextureManager & GetInstance()
	{
		static TextureManager instance;
		return instance;
	}
	std::vector<GLuint> textures;
	void LoadTexture(std::string const& filePath);
private:
	TextureManager();
	TextureManager(const TextureManager&);

};

