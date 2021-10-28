#include <sstream>
#include <fstream>
#include <iostream>

#include "shader_handler.h"

using namespace gameModule;

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
}

shaderHandler::~shaderHandler(void)
{

}

void shaderHandler::compile(const char *vertexCode, const char *fragmentCode)
{
	uint32_t vertexID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexID, 1, &vertexCode, NULL);
	glCompileShader(vertexID);

	uint32_t fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentID, 1, &fragmentCode, NULL);
	glCompileShader(fragmentID);

	shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexID);
	glAttachShader(shaderID, fragmentID);
	glLinkProgram(shaderID);
}

void shaderHandler::use(void)
{
	glUseProgram(shaderID);
}