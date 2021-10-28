#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

#include "shader_handler.h"

namespace gameModule
{
	class game
	{
	public:
		uint32_t screenWidth, screenHeight;
		uint32_t blockVAO;
		shaderHandler *quadShader;
	public:
		game(void);
		~game(void);
		void init(void);
		void render(void);
	};
}

#endif
