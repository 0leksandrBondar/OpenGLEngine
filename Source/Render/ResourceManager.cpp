#include "ResourceManager.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_ONLY_JPG
#include "stb_image.h"

#include "Texture2D.h"
#include "ShaderProgram.h"

#include <fstream>
#include <iostream>

std::shared_ptr<ShaderProgram> ResourceManager::loadShaderPrograms(const std::string& shaderName,
	const std::filesystem::path& vertexShaderSourcePath, const std::filesystem::path& fragmentShaderSourcePath)
{
	std::string fragShaderProgram;
	std::string vertShaderProgram;

	std::ifstream stream(vertexShaderSourcePath);
	if (!stream.is_open())
	{
		std::cerr << vertexShaderSourcePath.string() + " can not open some file " << std::endl;
		return nullptr;
	}
	vertShaderProgram = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
	stream.close();

	stream.open(fragmentShaderSourcePath);
	if (!stream.is_open())
	{
		std::cerr << fragmentShaderSourcePath.string() + "can not open some file " << std::endl;
		return nullptr;
	}
	fragShaderProgram = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
	stream.close();

	std::shared_ptr<ShaderProgram> newProgram = std::make_shared<ShaderProgram>(vertShaderProgram, fragShaderProgram);

	_shaderPrograms.insert({shaderName, newProgram});

	return newProgram;
}

std::shared_ptr<Texture2D> ResourceManager::loadTexture(const std::string& textureName, const std::filesystem::path& texturePath)
{
	int width = 0;
	int height = 0;
	int channels = 0;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* pixels = stbi_load(texturePath.string().c_str(), &width, &height, &channels, 0);

	if (!pixels)
	{
		std::cerr << "can not load texture";
		return nullptr;
	}

	std::shared_ptr<Texture2D> newTexture = std::make_shared<Texture2D>(width, height, pixels, channels, GL_NEAREST);
	stbi_image_free(pixels);

	_textures.insert({textureName,newTexture});
	return newTexture;
}

std::shared_ptr<Texture2D> ResourceManager::getTexture(const std::string& textureName)
{
	const auto it = _textures.find(textureName);
	if(it != _textures.cend())
	{
		return it->second;
	}
	else
	{
		std::cerr << "can not find texture " + textureName << std::endl;
		return nullptr;
	}
}

std::shared_ptr<ShaderProgram> ResourceManager::getShaderProgram(const std::string& shaderName)
{
	const auto it = _shaderPrograms.find(shaderName);
	if(it != _shaderPrograms.cend())
	{
		return it->second;
	}
	else
	{
		std::cerr << "can not find shader program " + shaderName << std::endl;
		return nullptr;
	}
}
