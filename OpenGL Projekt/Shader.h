#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"

class Shader
{
public:
	Shader(const std::string & fileName);
	~Shader();

	void Bind();
	void Update(const Transform& transform);

private:
	static const unsigned int NUM_SHADERS = 2;

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

