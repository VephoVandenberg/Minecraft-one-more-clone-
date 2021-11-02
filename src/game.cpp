#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "game.h"
#include "resource_manager.h"

using namespace gameModule;

game::game(uint32_t width, uint32_t height)
{
	screenWidth = width;
	screenHeight = height;
}

game::~game(void)
{
	delete cubeRenderer;
}

void game::init()
{
	resourceManager::loadShader("shaders/blockVertexShader.vert", "shaders/blockFragmentShader.frag", "cubeShader");
	
	cubeRenderer = new renderer(resourceManager::getShader("cubeShader"), screenWidth, screenHeight);
	gameCamera = new camera();
}

void game::render(float dt)
{
	cubeRenderer->drawObject();
}

void game::processInput(float dt)
{
	float speed = gameCamera->speed * dt;
	if (keys[GLFW_KEY_W])
	{
		gameCamera->cameraPos += gameCamera->cameraFront * speed;
	}
	else if(keys[GLFW_KEY_S])
	{
		gameCamera->cameraPos -= gameCamera->cameraFront * speed;
	}
	else if(keys[GLFW_KEY_A])
	{
		gameCamera->cameraPos -= glm::normalize(glm::cross(gameCamera->cameraFront, gameCamera->cameraUp)) * speed;
	}
	else if(keys[GLFW_KEY_D])
	{
		gameCamera->cameraPos += glm::normalize(glm::cross(gameCamera->cameraFront, gameCamera->cameraUp)) * speed;
	}
}

void game::update(float dt)
{
	gameCamera->updateCamera(resourceManager::getShader("cubeShader"), gameCamera->getViewMatrix(), "view");
}
