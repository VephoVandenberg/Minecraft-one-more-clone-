#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdint.h>

#include "src/game.h"

using namespace gameModule;

const uint32_t screenWidth 	= 1200;
const uint32_t screenHeight = 1000;

float lastX = screenWidth/2;
float lastY = screenHeight/2;

bool firstMouse = true;

void keysCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouseCallback(GLFWwindow *window, double xPos, double yPos);

game minecraft(screenWidth, screenHeight);

int main(int argc, char **argv)
{
	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW" << std::endl;
	}
	GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "YourCraft", NULL, NULL);
	glfwSetKeyCallback(window, keysCallback);
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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

		minecraft.processKeyboard(deltaTime);
		minecraft.render(deltaTime);
		minecraft.update(deltaTime);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	return 0;
}


void keysCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	if (key >= 0 && key <= 1024)
	{
		if (action == GLFW_PRESS)
		{
			minecraft.keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			minecraft.keys[key] = false;
		}
	}
}

void mouseCallback(GLFWwindow *window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	float xOffset = xPos - lastX;
	float yOffset = lastY - yPos;
	lastX = xPos;
	lastY = yPos;

	minecraft.gameCamera->updateCameraDirection(xOffset, yOffset);
}