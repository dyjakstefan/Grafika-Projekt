#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Projection.h"
#include <glm/gtc/type_ptr.hpp>
class Shader
{
public:
	Shader(const std::string & fileName);
	~Shader();

	void Bind();
	void Update(const Transform& model, const Transform& view, const Projection& projection);

private:
	static const unsigned int NUM_SHADERS = 2;

	enum
	{
		MODEL_U,
		VIEW_U,
		PROJECTION_U,
		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

