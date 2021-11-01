#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

#include "shader_handler.h"
#include "renderer.h"

namespace gameModule
{
	class game
	{
	public:
		uint32_t screenWidth, screenHeight;
		uint32_t blockVAO;
		uint32_t keys[1024];

		renderer *cubeRenderer;
	public:
		game(uint32_t screenWidth, uint32_t screenHeight);
		~game(void);
		void init(void);
		void render(float dt);
		void update(float dt);
		void processInput(void);
	};
}

#endif
