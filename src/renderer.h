#ifndef RENDERER_H
#define RENDERER_H

#include <stdint.h>

#include "shader_handler.h"

namespace gameModule
{
	class renderer
	{
	public:
		renderer(shaderHandler& sHandler);
		~renderer(void);

		void drawObject(void);
	private:
		shaderHandler cubeShader;
		uint32_t cubeVAO;

		void initRenderData(void);
	};
}

#endif
