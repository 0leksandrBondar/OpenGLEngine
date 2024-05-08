#include "ResourceManager.h"

#include "ShaderProgram.h"

#include <iostream>
#include <fstream>

std::shared_ptr<ShaderProgram> ResourceManager::loadShaderPrograms(
	const std::string& shaderName, const std::string& vertexShaderSourcePath, const std::string& fragmentShaderSourcePath)
{
	std::ifstream vert(vertexShaderSourcePath);
	std::ifstream frag(fragmentShaderSourcePath);

	std::string vertShaderProgram((std::istreambuf_iterator<char>(vert)),
		std::istreambuf_iterator<char>());

	std::string fragShaderProgram((std::istreambuf_iterator<char>(frag)),
		std::istreambuf_iterator<char>());

	std::shared_ptr<ShaderProgram> newProgram = std::make_shared<ShaderProgram>(vertShaderProgram,fragShaderProgram);
	_shaderPrograms.emplace(shaderName, newProgram);

	return newProgram;
}
