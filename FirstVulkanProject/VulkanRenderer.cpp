#include "VulkanRenderer.h"

int VulkanRenderer::init(GLFWwindow* new_window)
{
	window = new_window;
	
	try 
	{
		createInstance();
	}
	catch(const std::runtime_error &e)
	{
		printf("ERROR: %s\n", e.what());
		return EXIT_FAILURE;
	}
	
	return 0;
}

void VulkanRenderer::createInstance()
{

	// Information about the application itself
	// Most data here doesn't affect the program and is for developer convenience
	VkApplicationInfo appinfo = {};
	appinfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appinfo.pApplicationName = "Vulkan App";					// Custom name of the application
	appinfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);		// Custom version of the application
	appinfo.pEngineName = "No Engine";							// Custom Engine Name
	appinfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);			// Custom Engine Version
	appinfo.apiVersion = VK_API_VERSION_1_3;					// Vulkan Version (is important)

	// creation information for a VkInstance (Vulkan Instance)
	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pNext = nullptr;				// not required like the other parameter (not shown here)

	// create list to hold instance extensions
	std::vector<const char*> instanceExtensions = std::vector<const char*>();
	// Set up extensions Instance will use
	uint32_t glfwExtensionCount = 0;		// GLFW may require multiple extensions
	const char** glfwExtensions;			//Extensions passed as array of cstrings, so need a pointer (the array) to pointer (the cstring)
	// get extension by using GLFW
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	// Add GLFW extensions to list of extensions
	for (size_t i = 0; i < glfwExtensionCount; ++i)
	{
		instanceExtensions.push_back(glfwExtensions[i]);
	}

	createInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtensions.size());
	createInfo.ppEnabledExtensionNames = instanceExtensions.data();

	// is used for validation -- by default the are disabled
	// TODO: set up validation Layers that Instance will use
	createInfo.enabledLayerCount = 0;
	createInfo.ppEnabledLayerNames = nullptr;

	// create Instance
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

	if (result != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create a Vulkan Instance!");
	}

}

bool VulkanRenderer::checkInstanceExtensionSupport(std::vector<const char*>* checkExtensions)
{
	// need to get number of extensions to create array of correct size to hold extensions
	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	// create a list VKExtensionsProperties using count
	std::vector<VkExtensionProperties> extensions(extensionCount);
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

	//check if given extension
}
