#include "Shader.h"
#include <iostream>
#include <fstream>

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage);
static std::string LoadShader(const std::string & fileName);
static GLuint CreateShader(const std::string & text, GLenum shaderType);

Shader::Shader(const std::string & fileName)
{
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs.txt"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".fs.txt"), GL_FRAGMENT_SHADER);

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

void Shader::Bind()
{
	glUseProgram(m_program);
}

void Shader::Update(const Transform& model, const Camera& camera, const Projection& projection)
{
	glUniformMatrix4fv(m_uniforms[MODEL_U], 1, GL_FALSE, glm::value_ptr(model.GetModel()));
	glUniformMatrix4fv(m_uniforms[VIEW_U], 1, GL_FALSE, glm::value_ptr(camera.GetViewMatrix()));
	glUniformMatrix4fv(m_uniforms[PROJECTION_U], 1, GL_FALSE, glm::value_ptr(projection.GetProjection()));
}


void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string & errorMessage)
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

std::string LoadShader(const std::string & fileName)
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

GLuint CreateShader(const std::string & text, GLenum shaderType)
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
