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


	cubeRenderer = new renderer(resourceManager::getShader("cubeShader")); 
	/*
	float quadVertices[24] = {
		-0.5f, -0.5f, 0.0f,  0.1f, 0.5f, 0.5f,
		 0.5f, -0.5f, 0.0f,  0.5f, 0.3f, 0.5f,
		 0.5f,  0.5f, 0.0f,  0.5f, 0.5f, 0.5f,
		-0.5f,  0.5f, 0.0f,  0.5f, 0.4f, 0.5f
	};

	uint32_t quadInidices[6] = {
		0, 1, 2,
		0, 2, 3
	};

	uint32_t blockVBO, blockIBO;
	

	glGenVertexArrays(1, &blockVAO);
	glGenBuffers(1, &blockIBO);
	glGenBuffers(1, &blockVBO);

	glBindVertexArray(blockVAO);
	glBindBuffer(GL_ARRAY_BUFFER, blockVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, blockIBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadInidices), quadInidices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	*/
}

void game::render(void)
{
	cubeRenderer->drawObject();
}

void game::update(void)
{

}
