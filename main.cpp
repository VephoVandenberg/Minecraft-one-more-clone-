#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

#include "src/game.h"

using namespace gameModule;

const uint32_t screenWidth 	= 1200;
const uint32_t screenHeight = 1000;

game minecraft;

int main(int argc, char **argv)
{
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW" << std::endl;
	}
	GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "YourCraft", NULL, NULL);
	glfwMakeContextCurrent(window);
	
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Could not initialize GLEW" << std::endl; 
	}

	minecraft.init();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		minecraft.render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	return 0;
}
