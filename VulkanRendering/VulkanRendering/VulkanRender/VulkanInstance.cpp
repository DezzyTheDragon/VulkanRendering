#define GLFW_INCLUDE_VULKAN
#include "VulkanInstance.h"
#include <GLFW/glfw3.h>
#include <stdexcept>

VulkanInstance::VulkanInstance()
{
}

VulkanInstance::~VulkanInstance()
{
}

void VulkanInstance::NewInstance(VulkanData* data)
{
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Vulkan Render";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	uint32_t extensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&extensionCount);

	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = extensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	//TODO: Fix enum stuff
	if (vkCreateInstance(&createInfo, nullptr, &data->instance) != VK_SUCCESS)
	{
		throw std::runtime_error("VulkanInstance: Failed to create vulkan instance");
	}

}
