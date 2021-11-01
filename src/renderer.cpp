#include <GL/glew.h>

#include "renderer.h"

using namespace gameModule;

renderer::renderer(shaderHandler& shader)
{
	cubeShader = shader;
	initRenderData();
}

renderer::~renderer(void)
{

}

void renderer::initRenderData()
{
	float quadVertices[24] = {
		-0.5f, -0.5f, 0.0f,  0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f, 0.0f,  0.0f, 0.5f, 0.5f,
		 0.5f,  0.5f, 0.0f,  0.0f, 0.5f, 0.5f,
		-0.5f,  0.5f, 0.0f,  0.0f, 0.5f, 0.5f
	};

	uint32_t quadInidices[6] = {
		0, 1, 2,
		0, 2, 3
	};

	uint32_t blockVBO, blockIBO;
	

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &blockIBO);
	glGenBuffers(1, &blockVBO);

	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, blockVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, blockIBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadInidices), quadInidices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
}

void renderer::drawObject(void)
{
	cubeShader.use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}
