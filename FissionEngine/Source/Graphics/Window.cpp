#include "Window.h"

namespace Fission{
	f_Window::f_Window():
		f_width{640},
		f_height{480},
		f_title{"Window_1"},
		f_fullscreen{false}
	{
		for(int i = 0; i < GLFW_KEY_LAST; i++)
			f_keys[i] = false;
		for(int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++)
			f_mouseButtons[i] = false;
		this->init();
	}
	
	f_Window::f_Window(int width, int height, const char* title):
		f_width {width},
		f_height {height},
		f_title {title},
		f_fullscreen {false}
	{
		for(int i = 0; i < GLFW_KEY_LAST; i++)
			f_keys[i] = false;
		for(int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++)
			f_mouseButtons[i] = false;
		this->init();
	}

	f_Window::f_Window(int width, int height, const char* title, const bool fullscreen):
		f_width {width},
		f_height {height},
		f_title {title},
		f_fullscreen {fullscreen}
	{
		for(int i = 0; i < GLFW_KEY_LAST; i++)
			f_keys[i] = false;
		for(int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++)
			f_mouseButtons[i] = false;
		this->init();
	}

	f_Window::~f_Window(){
		glfwDestroyWindow(f_win);
		glfwTerminate();
	}

	static void windowResize(GLFWwindow* window, int width, int height){
		glfwMakeContextCurrent(window);
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mod){
		f_Window* win = (f_Window*)glfwGetWindowUserPointer(window);
		win->f_keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
		f_Window* win = (f_Window*)glfwGetWindowUserPointer(window);
		win->f_mouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
		f_Window* win = (f_Window*)glfwGetWindowUserPointer(window);
		win->f_xpos = xpos;
		win->f_ypos = ypos;
	}

	int f_Window::init()
	{

		if(!glfwInit()){
			LOG("ERROR: Could not initialize GLFW.\n" << getError(Critical_Error));
			return -1;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		f_win = glfwCreateWindow(f_width, f_height, f_title, NULL, NULL);

		if(f_fullscreen)
			this->activateFullscreen();

		if(!f_win){
			LOG("ERROR: could not identify a window pointer." << getError(Critical_Error));
			glfwDestroyWindow(f_win);
			glfwTerminate();
			return -1;
		}

		glfwMakeContextCurrent(f_win);
		glfwSetWindowUserPointer(f_win, this);
		glfwSetWindowSizeCallback(f_win, windowResize);

		if(glewInit() != GLEW_OK){
			LOG("ERROR: could not initialize GLEW." << getError(Critical_Error));
			return -1;
		}

		glfwSetKeyCallback(f_win, key_callback);
		glfwSetMouseButtonCallback(f_win, mouse_button_callback);
		glfwSetCursorPosCallback(f_win, cursor_position_callback);

		return 1;
	}

	void f_Window::activateFullscreen(){
		glfwSetWindowMonitor(f_win, glfwGetPrimaryMonitor(),
			0, 0, f_width, f_height, GLFW_REFRESH_RATE);
	}

	void f_Window::update(){
		glfwPollEvents();
		glfwGetFramebufferSize(f_win, &f_width, &f_height);
		glfwSwapBuffers(f_win);
	}

	void f_Window::clear(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool f_Window::close(){
		return glfwWindowShouldClose(f_win) == 1;
	}

	bool f_Window::isKeyPressed(unsigned int key)const {
		if(key >= GLFW_KEY_LAST)
			return false;
		else return f_keys[key];
	}

	bool f_Window::isMouseButtonPressed(unsigned int button)const {
		if(button >= GLFW_MOUSE_BUTTON_LAST)
			return false;
		else return f_mouseButtons[button];
	}

	void f_Window::getCursorPosition(double* x, double* y)const {
		*x = f_xpos;
		*y = f_ypos;
	}

}
