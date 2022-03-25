#define _CRTDGB_MAP_ALLOC
#include <crtdbg.h>

#include "VulkanRender/VulkanRender.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	VulkanRender* renderer = new VulkanRender();
	
	delete renderer;

	_CrtDumpMemoryLeaks();
	return 0;
}