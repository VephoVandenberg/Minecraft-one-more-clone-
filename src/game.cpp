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

	for (int x = 0; x < 5; x+=2)
	{
		for (int z = 0; z < 5; z+=2)
		{
			block blockObj(glm::vec3(x, 0.0f, z));
			blocks.push_back(blockObj);
		}
	}
}

void game::render(float dt)
{
	for (auto blockObj : blocks)
	{
		blockObj.draw(cubeRenderer);
	}
}

void game::processKeyboard(float dt)
{
	float speed = gameCamera->speed * dt;
	if (keys[GLFW_KEY_W])
	{
		gameCamera->cameraPos += gameCamera->cameraFront * speed;
	}
	if(keys[GLFW_KEY_S])
	{
		gameCamera->cameraPos -= gameCamera->cameraFront * speed;
	}
	if(keys[GLFW_KEY_A])
	{
		gameCamera->cameraPos -= glm::normalize(glm::cross(gameCamera->cameraFront, gameCamera->cameraUp)) * speed;
	}
	if(keys[GLFW_KEY_D])
	{
		gameCamera->cameraPos += glm::normalize(glm::cross(gameCamera->cameraFront, gameCamera->cameraUp)) * speed;
	}
}

void game::update(float dt)
{
	gameCamera->updateCamera(resourceManager::getShader("cubeShader"), gameCamera->getViewMatrix(), "view");
}
