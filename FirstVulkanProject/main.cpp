#define GLFW_INLCUDE_VULKAN
#include<GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "VulkanRenderer.h"


GLFWwindow* window;
VulkanRenderer vulkanRenderer;

void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	// initialize GLFW
	glfwInit();

	// set GLFW to NOT work with OpenGL
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr);		// c_str() converts c++ string into c style string

}

int main() 
{
	// create Window
	initWindow("TestWindow", 800, 600);

	// Create Vulkan Renderer Instance
	if (vulkanRenderer.init(window) == EXIT_FAILURE) { return EXIT_FAILURE; }


	// loop until closed
	while(!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}
	// destroy GLFW window and stop GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}