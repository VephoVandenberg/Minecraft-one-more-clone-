#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <glm/glm.hpp>

#include "shader_handler.h"

namespace gameModule
{
	class camera
	{
	public:
		glm::vec3 cameraPos;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;
		glm::mat4 view;

		float yaw = -90.0f;
		float pitch = 0.0f;
		float speed = 5.0f;
		float mouseSensitivity = 0.1f;

	public:
		camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f), 
			   glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), 
			   glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f));
		~camera(void);
		glm::mat4 getViewMatrix(void);
		void updateCamera(shaderHandler& shader, glm::mat4 matrix, std::string uniform);
		void updateCameraDirection(float xOffset, float yOffset);
	};
}

#endif
