#pragma once

#include "ISingleton.h"

#include <map>
#include <memory>
#include <string>

class ShaderProgram;

class ResourceManager : public ISingleton<ResourceManager>
{
public:
	ResourceManager() = default;

	std::shared_ptr<ShaderProgram> loadShaderPrograms(
		const std::string& shaderName, const std::string& vertexShaderSourcePath, const std::string& fragmentShaderSourcePath);

private:
	std::map<const std::string, std::shared_ptr<ShaderProgram>> _shaderPrograms;
};
