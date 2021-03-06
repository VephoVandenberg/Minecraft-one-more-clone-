#include <sstream>
#include <fstream>
#include <iostream>

#include "shader_handler.h"

using namespace gameModule;

shaderHandler::shaderHandler(void)
{
	
}

shaderHandler::shaderHandler(const char *vertexSrc, const char *fragmentSrc)
{
	std::ifstream vertexFile;
	std::ifstream fragmentFile;

	std::string vertexStringFile;
	std::string fragmentStringFile;

	vertexFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
	fragmentFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);

	try
	{
		vertexFile.open(vertexSrc);
		fragmentFile.open(fragmentSrc);

		std::stringstream vertexStream;
		std::stringstream fragmentStream;

		vertexStream << vertexFile.rdbuf();
		fragmentStream << fragmentFile.rdbuf();

		vertexStringFile = vertexStream.str();
		fragmentStringFile = fragmentStream.str();

		vertexFile.close();
		fragmentFile.close();
	}
	catch(std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILES_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char *vertexCode = vertexStringFile.c_str();
	const char *fragmentCode = fragmentStringFile.c_str();

	compile(vertexCode, fragmentCode);
}

shaderHandler::~shaderHandler(void)
{

}

void shaderHandler::compile(const char *vertexCode, const char *fragmentCode)
{
	int success;
	char infoLog[512];

	uint32_t vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vertexCode, NULL);
	glCompileShader(vertexID);
	glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION:\n " << infoLog << std::endl; 
	}

	uint32_t fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fragmentCode, NULL);
	glCompileShader(fragmentID);
	glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION:\n " << infoLog << std::endl; 
	}

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexID);
	glAttachShader(shaderID, fragmentID);
	glLinkProgram(shaderID);
}

void shaderHandler::use(void)
{
	glUseProgram(shaderID);
}

void shaderHandler::setMatrix4f(glm::mat4 matrix, std::string name)
{
	glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &matrix[0][0]);
}
