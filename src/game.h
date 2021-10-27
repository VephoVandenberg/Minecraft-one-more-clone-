#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace gameModule
{
	class game
	{
	public:
		GLFWwindow *window;
	public:
		game(void);
		~game(void);
		void init(void);
	};
}

#endif