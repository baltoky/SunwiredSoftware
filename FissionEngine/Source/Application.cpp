#define GLEW_STATIC

#include <iostream>
#include <GLFW/glfw3.h>

#define LOG(x) std::cout << x \
	<< " l: " << __LINE__ <<\
	" f: " << __FILE__ << std::endl;

int main(int argc, char** argv)
{
	GLFWwindow* win;

	if(!glfwInit()){
		LOG("Cannot initialize GLFW");
		return -1;
	}

	win = glfwCreateWindow(800, 500, "Fission Engine", NULL, NULL);
	if(!win){
		LOG("Could not create a window.");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(win);

	while(!glfwWindowShouldClose(win)){
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(win);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
