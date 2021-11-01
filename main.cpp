#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

#include "src/game.h"

using namespace gameModule;

const uint32_t screenWidth 	= 1200;
const uint32_t screenHeight = 1000;

game minecraft(screenWidth, screenHeight);

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

	glEnable(GL_DEPTH_TEST);

	minecraft.init();

	float lastFrame = 0.0f;
	float deltaTime = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

		minecraft.render(deltaTime);
		minecraft.update(deltaTime);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	return 0;
}
