#pragma once
#include "VulkanStructs.h"

class VulkanRender
{
public: 
	VulkanRender();
	~VulkanRender();
private:
	void InitWindow();
	void MainLoop();

	VulkanData vkData;

	const uint32_t WIDTH = 800;
	const uint32_t HIGHT = 600;
};