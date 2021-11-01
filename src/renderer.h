#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>

#include "shader_handler.h"

namespace gameModule
{
	class renderer
	{
	public:
		renderer(shaderHandler& sHandler, uint32_t width, uint32_t height);
		~renderer(void);

		void drawObject(void);
	private:
		shaderHandler cubeShader;
		uint32_t cubeVAO;
		uint32_t screenWidth, screenHeight;

		void initRenderData(void);
	};
}

#endif
