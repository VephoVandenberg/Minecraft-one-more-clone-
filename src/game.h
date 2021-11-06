#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>
#include <vector>

#include "shader_handler.h"
#include "camera.h"
#include "renderer.h"
#include "block.h"

namespace gameModule
{
	class game
	{
	public:
		uint32_t screenWidth, screenHeight;
		uint32_t blockVAO;
		uint32_t keys[1024];

		renderer *cubeRenderer;
		camera 	 *gameCamera;
		std::vector<block> blocks;
	public:
		game(uint32_t screenWidth, uint32_t screenHeight);
		~game(void);
		void init(void);
		void render(float dt);
		void update(float dt);
		void processKeyboard(float dt);
		void processMouse(void);
	};
}

#endif
