#define GLEW_STATIC

#include "./Utilities/LogSystem.h"
#include "./Utilities/ErrorSystem.h"
#include "./Graphics/Window.h"
#include "./Utilities/FileSystem.h"
#include <iostream>
#include <GLFW/glfw3.h>
#include <string>

int main(int argc, char** argv)
{
	char* filepath;
	if(argc > 1)
		filepath = argv[1];
	else filepath = (char*)"./text.txt";

	Fission::f_Window* window = new Fission::f_Window();

	while(!(*window).close())
	{
		(*window).update();
		(*window).clear();
		if((*window).isKeyPressed(GLFW_KEY_ESCAPE)){
			LOG("Key was pressed");
			glfwSetWindowShouldClose((*window).getWindowPointer(), true);
		}
	}

	return 0;
}
