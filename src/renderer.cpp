#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "renderer.h"

using namespace gameModule;

renderer::renderer(shaderHandler& shader, uint32_t width, uint32_t height)
{
	cubeShader = shader;
	screenWidth = width;
	screenHeight = height;

	initRenderData();
}

renderer::~renderer(void)
{

}

void renderer::initRenderData()
{
	float cubeVertices[6*24] = {
		 // position		 // color
		-0.5f, -0.5f, 0.5f,   0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f, 0.5f,   0.0f, 0.5f, 0.5f,
		 0.5f,  0.5f, 0.5f,   0.0f, 0.5f, 0.5f,
		-0.5f,  0.5f, 0.5f,   0.0f, 0.5f, 0.5f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,

		-0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.5f,
		-0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.5f,

		-0.5f, 0.5f,  0.5f,   0.0f, 0.5f, 0.5f,
		 0.5f, 0.5f,  0.5f,   0.0f, 0.5f, 0.5f,
		 0.5f, 0.5f, -0.5f,   0.0f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f,   0.0f, 0.5f, 0.5f,

		 0.5f,  0.5f,  0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,
		 0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.5f,

		-0.5f,  0.5f,  0.5f,  0.0f, 0.5f, 0.5f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.5f,
		-0.5f,  0.5f, -0.5f,  0.0f, 0.5f, 0.5f

	};

	uint32_t quadInidices[6*6] = {
		0, 1, 2,
		0, 2, 3,

		1, 2, 3,
		1, 3, 4,

		2, 3, 4,
		2, 4, 5,

		3, 4, 5,
		3, 5, 6,

		4, 5, 6,
		4, 6, 7,

		5, 6, 7,
		5, 7, 8
	};

	uint32_t blockVBO, blockIBO;

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &blockIBO);
	glGenBuffers(1, &blockVBO);

	glBindVertexArray(cubeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, blockVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, blockIBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadInidices), quadInidices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
}

void renderer::drawObject(void)
{
	glm::mat4 model 		= glm::mat4(1.0f);
	glm::mat4 view 			= glm::mat4(1.0f);
	glm::mat4 projection;

	model = glm::rotate(model, glm::radians(-40.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::translate(view, glm::vec3(0.0f, 0.1f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)(screenWidth/screenHeight), 0.1f, 100.0f); 

	cubeShader.setMatrix4f(model, "model");
	cubeShader.setMatrix4f(view, "view");
	cubeShader.setMatrix4f(projection, "projection");

	cubeShader.use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}
