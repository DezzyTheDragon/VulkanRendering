#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include "VulkanRender.h"


VulkanRender::VulkanRender()
{
	InitWindow();
	//init vulkan
	MainLoop();
	//don't call cleanup because that is in deconstructor
}

VulkanRender::~VulkanRender()
{
	glfwDestroyWindow(vkData.window);

	glfwTerminate();
}

void VulkanRender::InitWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);	//don't use open gl context
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);		//no resize for simplicity
	vkData.window = glfwCreateWindow(WIDTH, HIGHT, "Vulkan Render", nullptr, nullptr);
}

void VulkanRender::MainLoop()
{
	while (!glfwWindowShouldClose(vkData.window))
	{
		glfwPollEvents();
	}
}
