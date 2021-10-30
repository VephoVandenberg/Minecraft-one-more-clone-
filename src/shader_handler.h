#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
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
		void use(void);
	private:
		uint32_t shaderID;
	};
}

#endif
