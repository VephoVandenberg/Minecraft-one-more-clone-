#include "resource_manager.h"

using namespace gameModule;

std::map<std::string, shaderHandler> resourceManager::shaders;

shaderHandler resourceManager::loadShader(const char *vertexFile, const char *fragmentFile, std::string shaderName)
{
	shaderHandler desiredShader(vertexFile, fragmentFile);
	shaders[shaderName] = desiredShader;
	return shaders[shaderName];
}

shaderHandler resourceManager::getShader(std::string name)
{
	return shaders[name];
}
