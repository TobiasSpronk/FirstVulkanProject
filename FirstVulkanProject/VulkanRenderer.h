#pragma once

#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <stdexcept>
#include <vector>

class VulkanRenderer
{
public: 
	int init(GLFWwindow* new_window);


private:
	GLFWwindow * window;
	
	// Vulkan Components
	VkInstance instance;

	// Vulkan Functions
	// create Functions
	void createInstance();

	// Support Functions
	bool VulkanRenderer::checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions);


};

