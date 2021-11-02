#include <glm/gtc/matrix_transform.hpp>

#include "camera.h"

using namespace gameModule;

camera::camera(glm::vec3 position, glm::vec3 up, glm::vec3 front)
{
	cameraPos = position;
	cameraUp = up;
	cameraFront = front;
}

camera::~camera(void)
{

}

glm::mat4 camera::getViewMatrix(void)
{
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void camera::updateCamera(shaderHandler& shader, glm::mat4 matrix, std::string uniform)
{
	shader.setMatrix4f(matrix, uniform);
}


void camera::updateCameraDirection(double x, double y)
{

}
