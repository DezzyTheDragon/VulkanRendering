#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

struct VulkanData
{
	GLFWwindow* window = nullptr;
	VkInstance instance = VK_NULL_HANDLE;
};