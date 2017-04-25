#include "Shader.h"
#include <iostream>
#include <fstream>

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);
static std::string LoadShader(const std::string & fileName);
static GLuint CreateShader(const std::string & text, GLenum shaderType);

Shader::Shader()
{
}

Shader::Shader(const std::string & fileName)
{
	Initialize(fileName);
}


Shader::~Shader()
{
	for (int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	glDeleteProgram(m_program);
}

void Shader::Initialize(const std::string & fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".frag"), GL_FRAGMENT_SHADER);

	for (int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(m_program, m_shaders[i]);

	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

	m_uniforms[MODEL_U] = glGetUniformLocation(m_program, "model");
	m_uniforms[VIEW_U] = glGetUniformLocation(m_program, "view");
	m_uniforms[PROJECTION_U] = glGetUniformLocation(m_program, "projection");
	m_uniforms[VIEWPOS_U] = glGetUniformLocation(m_program, "viewPos");
	m_uniforms[M_AMBIENT_U] = glGetUniformLocation(m_program, "material.ambient");
	m_uniforms[M_DIFFUSE_U] = glGetUniformLocation(m_program, "material.diffuse");
	m_uniforms[M_SPECULAR_U] = glGetUniformLocation(m_program, "material.specular");
	m_uniforms[M_SHININESS_U] = glGetUniformLocation(m_program, "material.shininess");

	m_uniforms[L_DIRECTION_U] = glGetUniformLocation(m_program, "dirLight.direction");
	m_uniforms[L_AMBIENT_U] = glGetUniformLocation(m_program, "dirLight.ambient");
	m_uniforms[L_DIFFUSE_U] = glGetUniformLocation(m_program, "dirLight.diffuse");
	m_uniforms[L_SPECULAR_U] = glGetUniformLocation(m_program, "dirLight.specular");
	
	m_uniforms[L_POSITION_0_U] = glGetUniformLocation(m_program, "pointLights[0].position");
	m_uniforms[L_AMBIENT_0_U] = glGetUniformLocation(m_program, "pointLights[0].ambient");
	m_uniforms[L_DIFFUSE_0_U] = glGetUniformLocation(m_program, "pointLights[0].diffuse");
	m_uniforms[L_SPECULAR_0_U] = glGetUniformLocation(m_program, "pointLights[0].specular");
	m_uniforms[L_CONSTANT_0_U] = glGetUniformLocation(m_program, "pointLights[0].constant");
	m_uniforms[L_LINEAR_0_U] = glGetUniformLocation(m_program, "pointLights[0].linear");
	m_uniforms[L_QUADRATIC_0_U] = glGetUniformLocation(m_program, "pointLights[0].quadratic");

	m_uniforms[L_POSITION_1_U] = glGetUniformLocation(m_program, "pointLights[1].position");
	m_uniforms[L_AMBIENT_1_U] = glGetUniformLocation(m_program, "pointLights[1].ambient");
	m_uniforms[L_DIFFUSE_1_U] = glGetUniformLocation(m_program, "pointLights[1].diffuse");
	m_uniforms[L_SPECULAR_1_U] = glGetUniformLocation(m_program, "pointLights[1].specular");
	m_uniforms[L_CONSTANT_1_U] = glGetUniformLocation(m_program, "pointLights[1].constant");
	m_uniforms[L_LINEAR_1_U] = glGetUniformLocation(m_program, "pointLights[1].linear");
	m_uniforms[L_QUADRATIC_1_U] = glGetUniformLocation(m_program, "pointLights[1].quadratic");

	m_uniforms[L_POSITION_2_U] = glGetUniformLocation(m_program, "pointLights[2].position");
	m_uniforms[L_AMBIENT_2_U] = glGetUniformLocation(m_program, "pointLights[2].ambient");
	m_uniforms[L_DIFFUSE_2_U] = glGetUniformLocation(m_program, "pointLights[2].diffuse");
	m_uniforms[L_SPECULAR_2_U] = glGetUniformLocation(m_program, "pointLights[2].specular");
	m_uniforms[L_CONSTANT_2_U] = glGetUniformLocation(m_program, "pointLights[2].constant");
	m_uniforms[L_LINEAR_2_U] = glGetUniformLocation(m_program, "pointLights[2].linear");
	m_uniforms[L_QUADRATIC_2_U] = glGetUniformLocation(m_program, "pointLights[2].quadratic");

	m_uniforms[L_POSITION_3_U] = glGetUniformLocation(m_program, "pointLights[3].position");
	m_uniforms[L_AMBIENT_3_U] = glGetUniformLocation(m_program, "pointLights[3].ambient");
	m_uniforms[L_DIFFUSE_3_U] = glGetUniformLocation(m_program, "pointLights[3].diffuse");
	m_uniforms[L_SPECULAR_3_U] = glGetUniformLocation(m_program, "pointLights[3].specular");
	m_uniforms[L_CONSTANT_3_U] = glGetUniformLocation(m_program, "pointLights[3].constant");
	m_uniforms[L_LINEAR_3_U] = glGetUniformLocation(m_program, "pointLights[3].linear");
	m_uniforms[L_QUADRATIC_3_U] = glGetUniformLocation(m_program, "pointLights[3].quadratic");

}

void Shader::Bind()
{
	glUseProgram(m_program);
}

void Shader::Update(const Transform& model, const Camera& camera, const Projection& projection, const Material material)
{
	glUniformMatrix4fv(m_uniforms[MODEL_U], 1, GL_FALSE, glm::value_ptr(model.GetModel()));
	glUniformMatrix4fv(m_uniforms[VIEW_U], 1, GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
	glUniformMatrix4fv(m_uniforms[PROJECTION_U], 1, GL_FALSE, glm::value_ptr(projection.GetProjection()));
	glUniform3f(m_uniforms[VIEWPOS_U], camera.m_position.x, camera.m_position.y, camera.m_position.z);
	glUniform3f(m_uniforms[M_AMBIENT_U], material.ambient.x, material.ambient.y, material.ambient.z);
	glUniform3f(m_uniforms[M_DIFFUSE_U], material.diffuse.x, material.diffuse.y, material.diffuse.z);
	glUniform3f(m_uniforms[M_SPECULAR_U], material.specular.x, material.specular.y, material.specular.z);
	glUniform1f(m_uniforms[M_SHININESS_U], material.shininess);

	glUniform3f(m_uniforms[L_DIRECTION_U], -0.2f, -1.0f, -0.3f);
	glUniform3f(m_uniforms[L_AMBIENT_U], 0.2f, 0.2f, 0.2f);
	glUniform3f(m_uniforms[L_DIFFUSE_U], 0.5f, 0.5f, 0.5f);
	glUniform3f(m_uniforms[L_SPECULAR_U], 1.0f, 1.0f, 1.0f);

	glUniform3f(m_uniforms[L_POSITION_0_U], 1.5f, 3.5f, 1.5f);
	glUniform3f(m_uniforms[L_AMBIENT_0_U], 0.05f, 0.05f, 0.05f);
	glUniform3f(m_uniforms[L_DIFFUSE_0_U], 0.8f, 0.8f, 0.8f);
	glUniform3f(m_uniforms[L_SPECULAR_0_U], 1.0f, 1.0f, 1.0f);
	glUniform1f(m_uniforms[L_CONSTANT_0_U], 1.0f);
	glUniform1f(m_uniforms[L_LINEAR_0_U], 0.09);
	glUniform1f(m_uniforms[L_QUADRATIC_0_U], 0.032);

	glUniform3f(m_uniforms[L_POSITION_1_U], -1.5f, 3.5f, 1.5f);
	glUniform3f(m_uniforms[L_AMBIENT_1_U], 0.05f, 0.05f, 0.05f);
	glUniform3f(m_uniforms[L_DIFFUSE_1_U], 0.8f, 0.8f, 0.8f);
	glUniform3f(m_uniforms[L_SPECULAR_1_U], 1.0f, 1.0f, 1.0f);
	glUniform1f(m_uniforms[L_CONSTANT_1_U], 1.0f);
	glUniform1f(m_uniforms[L_LINEAR_1_U], 0.09);
	glUniform1f(m_uniforms[L_QUADRATIC_1_U], 0.032);

	glUniform3f(m_uniforms[L_POSITION_2_U], 1.5f, 3.5f, -1.5f);
	glUniform3f(m_uniforms[L_AMBIENT_2_U], 0.05f, 0.05f, 0.05f);
	glUniform3f(m_uniforms[L_DIFFUSE_2_U], 0.8f, 0.8f, 0.8f);
	glUniform3f(m_uniforms[L_SPECULAR_2_U], 1.0f, 1.0f, 1.0f);
	glUniform1f(m_uniforms[L_CONSTANT_2_U], 1.0f);
	glUniform1f(m_uniforms[L_LINEAR_2_U], 0.09);
	glUniform1f(m_uniforms[L_QUADRATIC_2_U], 0.032);

	glUniform3f(m_uniforms[L_POSITION_3_U], -1.5f, 3.5f, -1.5f);
	glUniform3f(m_uniforms[L_AMBIENT_3_U], 0.05f, 0.05f, 0.05f);
	glUniform3f(m_uniforms[L_DIFFUSE_3_U], 0.8f, 0.8f, 0.8f);
	glUniform3f(m_uniforms[L_SPECULAR_3_U], 1.0f, 1.0f, 1.0f);
	glUniform1f(m_uniforms[L_CONSTANT_3_U], 1.0f);
	glUniform1f(m_uniforms[L_LINEAR_3_U], 0.09);
	glUniform1f(m_uniforms[L_QUADRATIC_3_U], 0.032);
}


void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << errorMessage << ": " << error << "'" << std::endl;
	}
}

std::string Shader::LoadShader(const std::string & fileName)
{
	std::fstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.good())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}

	return output;
}

GLuint Shader::CreateShader(const std::string & text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0)
		std::cerr << "Error: shader creation failed!" << std::endl;

	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];

	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");


	return shader;
}
