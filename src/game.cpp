#include <iostream>

#include "game.h"

using namespace gameModule;

game::game(void)
{
}

game::~game(void)
{
	delete quadShader;
}

void game::init()
{
	quadShader = new shaderHandler("shaders/blockVertexShader.vert", "shaders/blockFragmentShader.frag");

	float quadVertices[12] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
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
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void game::render(void)
{
	quadShader->use();
	glBindVertexArray(blockVAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}
