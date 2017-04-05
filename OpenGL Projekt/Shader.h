#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Projection.h"
#include "Camera.h"
#include <glm/gtc/type_ptr.hpp>
class Shader
{
public:
	Shader();
	Shader(const std::string & fileName);
	~Shader();

	void Initialize(const std::string & fileName);
	void Bind();
	void Update(const Transform& model, const Camera& view, const Projection& projection);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);
	std::string Shader::LoadShader(const std::string & fileName);
	GLuint Shader::CreateShader(const std::string & text, GLenum shaderType);

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

