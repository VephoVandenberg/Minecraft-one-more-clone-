#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "block.h"
#include "renderer.h"

namespace gameModule
{
	class world
	{
	public:
		std::vector<block> blocks;

	public:
		world(void);
		~world(void);

		void render(renderer *rendererObj);
	};
}

#endif
