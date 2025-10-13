#pragma once

#include "Window.h"
#include "Shader.h"

class Renderer {
private:
	// core components
	Window* window;          // GLFW window handler
	Shader* basicShader;	 // Defualt Shader for Drawing

	unsigned int VAO, VBO;
	unsigned int maxVertices;

	int width, height;

	//void initGL();			// Sets OpenGL states
	//void setupShaders();	// Loads and Compile shaders
	void setupBuffers();	// Uploads vertex Data to gpu
	//void processInput();	// handles input
	void renderFrame(float* vertexData, unsigned int vertexCount);		// clears screen and draw each frame

public:
	Renderer(int width, int height, const char* title);
	~Renderer();

	void run();		// starts the render loop
};