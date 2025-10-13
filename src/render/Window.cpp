#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}


Window::Window(int width, int height, const std::string& title) {
	this->width = width;
	this->height = height;

	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW, terminating the program";
		exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	handle = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

	if (!handle) {
		std::cerr << "Failed to create window, terminating the program";
		exit(-1);
	}

	glfwMakeContextCurrent(handle);

	glfwSwapInterval(1);

	std::cout << "Window created" << std::endl;
}

void Window::createContext() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD, terminating the program";
		exit(-1);
	}

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(handle, framebuffer_size_callback);
}
	

bool Window::shouldClose() const{
	return glfwWindowShouldClose(handle);
}

void Window::swapBuffers() {
	glfwSwapBuffers(handle);
}

void Window::pollEvents() {
	glfwPollEvents();
}

Window::~Window() {
	glfwDestroyWindow(handle);
	glfwTerminate();
}

GLFWwindow* Window::getHandle() const{
	return handle;
}