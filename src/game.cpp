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
}

void game::render(float dt)
{
	cubeRenderer->drawObject();
}

void game::update(float dt)
{

}
