#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Renderer.h"
#include "Window.h"
#include "Shader.h"

Renderer::Renderer(int width, int height, const char* title) {
	this->height = height;
	this->width = width;

	window = new Window(width, height, "Engine");

	window->createContext();

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

	basicShader = new Shader("../shaders/basic.vert", "../shaders/basic.frag");

	maxVertices = 1000;
	setupBuffers();
}

Renderer::~Renderer() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	delete basicShader;
	delete window;
}

void Renderer::setupBuffers() {
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * maxVertices * 3, nullptr, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
}

void Renderer::renderFrame(float* vertexData, unsigned int vertexCount) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	basicShader->use();

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * vertexCount * 3, vertexData);

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);

	glBindVertexArray(0);
}

void Renderer::run() {
	float dummyVertices[9] = {
		0.0f, 0.5f, 0.0f,
	   -0.5f,-0.5f, 0.0f,
		0.5f,-0.5f, 0.0f
	};

	while (!window->shouldClose()) {
		renderFrame(dummyVertices, 3);


		window->swapBuffers();
		window->pollEvents();
	}
}