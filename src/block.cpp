#include "block.h"

using namespace gameModule;

block::block(glm::vec3 positionInput)
{
	position = positionInput;
}

block::~block(void)
{

}

void block::draw(renderer *rendererObj)
{
	rendererObj->drawObject(position);
}
