#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include "Shader.h"


Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
	std::string vertexCode = loadSourceFromFile(vertexPath);
	std::string fragmentCode = loadSourceFromFile(fragmentPath);

	unsigned int vertexShader = compileShader(vertexCode, GL_VERTEX_SHADER);
	unsigned int fragmentShader = compileShader(fragmentCode, GL_FRAGMENT_SHADER);


	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader() {
	glDeleteProgram(programID);
}

unsigned int Shader::compileShader(const std::string& source, unsigned int type) {
	unsigned int shader = glCreateShader(type);
	const char* sourceCode = source.c_str();
	glShaderSource(shader, 1, &sourceCode, NULL);
	glCompileShader(shader);

	return shader;
}

std::string Shader::loadSourceFromFile(const std::string& filepath) {
	std::ifstream file(filepath);
	if (!file.is_open()) {
		std::cerr << "Failed to open the shader file, terminating the program. FilePath: " << filepath << std::endl;
		exit(-1);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	return buffer.str();
}

void Shader::use() const{
	glUseProgram(programID);
}

unsigned int Shader::getID() const {
	return programID;
}

void Shader::setMat4(const std::string& name, const glm::mat4& value) {

}

void Shader::setVec3(const std::string& name, const glm::vec3& value) {

}

void Shader::setFloat(const std::string& name, float value) {

}
