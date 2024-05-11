#pragma once

#include "OpenGl.h"

#include <string>

class ShaderProgram
{
public:
	ShaderProgram() = delete;
	ShaderProgram(const ShaderProgram&) = delete;
	ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgram& operator=(const ShaderProgram&) = delete;

	~ShaderProgram();

	void useShader() const;
	void setID(const std::string& name, const GLint value);

	[[nodiscard]] const bool isCompiled() const {return _isCompiled;};
	[[nodiscard]] GLuint getProgramId() const {return _Id;};

private:
	void linkShaderProgram(const GLuint vertexShaderID, const GLuint fragmentShaderID);
	bool createShaderProgram(const std::string& source, const GLenum shaderType, GLuint& shaderId);

private:
	GLuint _Id {0};
	bool _isCompiled {false};
};