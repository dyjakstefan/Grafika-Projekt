#pragma once
#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Projection.h"
#include "Camera.h"
#include "Material.h"
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader();
	Shader(const std::string & fileName);
	~Shader();

	void Initialize(const std::string & fileName);
	void Bind();
	void Update(const Transform& model, const Camera& view, const Projection& projection, const Material material);
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
		VIEWPOS_U,
		M_AMBIENT_U,
		M_DIFFUSE_U,
		M_SPECULAR_U,
		M_SHININESS_U,

		L_DIRECTION_U,
		L_AMBIENT_U,
		L_DIFFUSE_U,
		L_SPECULAR_U,

		L_POSITION_0_U,
		L_AMBIENT_0_U,
		L_DIFFUSE_0_U,
		L_SPECULAR_0_U,
		L_CONSTANT_0_U,
		L_LINEAR_0_U,
		L_QUADRATIC_0_U,

		L_POSITION_1_U,
		L_AMBIENT_1_U,
		L_DIFFUSE_1_U,
		L_SPECULAR_1_U,
		L_CONSTANT_1_U,
		L_LINEAR_1_U,
		L_QUADRATIC_1_U,

		L_POSITION_2_U,
		L_AMBIENT_2_U,
		L_DIFFUSE_2_U,
		L_SPECULAR_2_U,
		L_CONSTANT_2_U,
		L_LINEAR_2_U,
		L_QUADRATIC_2_U,

		L_POSITION_3_U,
		L_AMBIENT_3_U,
		L_DIFFUSE_3_U,
		L_SPECULAR_3_U,
		L_CONSTANT_3_U,
		L_LINEAR_3_U,
		L_QUADRATIC_3_U,
		
		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

