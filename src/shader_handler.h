#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <stdint.h>

namespace gameModule
{
	class shaderHandler
	{
	public:
		shaderHandler(void);
		shaderHandler(const char *vertexSrc, const char *fragmentSrc);
		~shaderHandler(void);
		void compile(const char *vertexCode, const char *fragmentCode);
		void setMatrix4f(glm::mat4 matrix, std::string);
		void use(void);
	private:
		uint32_t shaderID;
	};
}

#endif
