#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window {
private:
	GLFWwindow* handle;
	int width, height;
	std::string title;

public:
	Window(int width, int height, const std::string& title);
	~Window();

	void createContext();			// Initialize the GLFW and create openGL context
	bool shouldClose() const;		// return true if user request close
	void swapBuffers();				// swap the front/back buffers
	void pollEvents();				// poll window/input events
	GLFWwindow* getHandle() const;	// expose raw glfw window when needed

};