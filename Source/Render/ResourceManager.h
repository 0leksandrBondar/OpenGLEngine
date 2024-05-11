#pragma once

#include "ISingleton.h"

#include <filesystem>
#include <memory>
#include <unordered_map>

class Texture2D;
class ShaderProgram;

class ResourceManager : public ISingleton<ResourceManager>
{
public:

	std::shared_ptr<ShaderProgram> loadShaderPrograms(const std::string& shaderName,
		const std::filesystem::path& vertexShaderSourcePath, const std::filesystem::path& fragmentShaderSourcePath);

	std::shared_ptr<Texture2D> loadTexture(const std::string& textureName, const std::filesystem::path& texturePath);


	std::shared_ptr<Texture2D> getTexture(const std::string& textureName);
	std::shared_ptr<ShaderProgram> getShaderProgram(const std::string& shaderName);

private:
	std::unordered_map<std::string, std::shared_ptr<Texture2D>> _textures;
	std::unordered_map<std::string, std::shared_ptr<ShaderProgram>> _shaderPrograms;
};
