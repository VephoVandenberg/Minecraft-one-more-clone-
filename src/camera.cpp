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


void camera::updateCameraDirection(float xOffset, float yOffset)
{
	xOffset *= mouseSensitivity;
	yOffset *= mouseSensitivity;

	yaw += xOffset;
	pitch += yOffset;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}


	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}
