#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>
#include <map>

#include "shader_handler.h"

namespace gameModule
{
	class resourceManager
	{
	public:
		static std::map<std::string, shaderHandler> shaders;
	public:
		static shaderHandler loadShader(const char *vertexFile, const char *fragmentFile, std::string shaderName);
		static shaderHandler getShader(std::string name);
	private:
		resourceManager();
	};
}


#endif
