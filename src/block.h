#ifndef BLOCK_H
#define BLOCK_H

#include <glm/glm.hpp>

#include "renderer.h"

namespace gameModule
{
	class block
	{
	public:
		block(glm::vec3 positionInput = glm::vec3(0.0f, 0.0f, 0.0f));
		~block(void);
		
		void draw(renderer *rendererObj);

	private:
		glm::vec3 position;
	};
}

#endif
