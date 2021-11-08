#include "world.h"

using namespace gameModule;

world::world(void)
{
	for (int z = 0; z < 5; z++)
	{
		for (int x = 0; x < 5; x++)
		{
			block blockObj(glm::vec3(x, 0.0f, z));
			blocks.push_back(blockObj);
		}
	}
}

world::~world(void)
{

}

void world::render(renderer *rendererObj)
{
	for (int worldIterator = 0; worldIterator < blocks.size(); worldIterator++)
	{
		blocks[worldIterator].draw(rendererObj);
	}
}
