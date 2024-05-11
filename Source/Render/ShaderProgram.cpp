#include "ShaderProgram.h"

#include <iostream>

ShaderProgram::ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
	GLuint vertexShaderID = 0, fragmentShaderID = 0;
	if (!createShaderProgram(vertexShader, GL_VERTEX_SHADER, vertexShaderID) ||
		!createShaderProgram(fragmentShader, GL_FRAGMENT_SHADER, fragmentShaderID))
	{
		std::cerr << "ShaderProgram::ShaderProgram : compile shader error \n";
		return;
	}
	linkShaderProgram(vertexShaderID, fragmentShaderID);
}

bool ShaderProgram::createShaderProgram(const std::string& source, const GLenum shaderType, GLuint& shaderId)
{
	const char* shaderCode = source.c_str();

	shaderId = glCreateShader(shaderType);
	glShaderSource(shaderId, 1, &shaderCode, nullptr);
	glCompileShader(shaderId);

	GLint status = false;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &status);

	if (!status)
	{
		std::cerr << "ShaderProgram::createShaderProgram : compile shader error \n";
		return false;
	}

	return true;
}

void ShaderProgram::linkShaderProgram(const GLuint vertexShaderID, const GLuint fragmentShaderID)
{
	_Id = glCreateProgram();
	glAttachShader(_Id, vertexShaderID);
	glAttachShader(_Id, fragmentShaderID);
	glLinkProgram(_Id);

	GLint status = false;
	glGetProgramiv(_Id, GL_LINK_STATUS, &status);
	if (!status)
	{
		std::cerr << "ShaderProgram::linkShaderProgram : link shaderProgram error";
	}
	else
	{
		_isCompiled = true;
	}
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(_Id);
}

void ShaderProgram::useShader() const
{
	glUseProgram(_Id);
}