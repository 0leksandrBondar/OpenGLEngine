#pragma once

#include "OpenGl.h"

#include <string>

class ShaderProgram
{
public:
	ShaderProgram() = delete;
	ShaderProgram(const ShaderProgram&) = delete;
	ShaderProgram& operator=(const ShaderProgram&) = delete;

	ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
	~ShaderProgram();

	void useShader() const;

	const bool isCompiled() const {return _isCompiled;};
	const GLuint getProgramId() const {return _Id;};

private:
	void linkShaderProgram(const GLuint vertexShaderID, const GLuint fragmentShaderID);
	bool createShaderProgram(const std::string& source, const GLenum shaderType, GLuint& shaderId);

private:
	GLuint _Id {0};
	bool _isCompiled {false};
};