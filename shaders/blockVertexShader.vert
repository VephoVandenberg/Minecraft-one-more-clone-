#version 330 core 

layout (location = 0) in vec3 inputPosition;
layout (location = 1) in vec3 inputColor;

out vec4 colorCoords;

void main(void)
{
	gl_Position = vec4(inputPosition, 1.0f);
	colorCoords = vec4(inputColor, 1.0f);
}

