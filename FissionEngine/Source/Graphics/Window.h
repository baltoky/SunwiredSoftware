#pragma once

#define GLEW_STATIC
#include "./../Utilities/LogSystem.h"
#include "./../Utilities/ErrorSystem.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Fission{
	class f_Window{
		private:
			GLFWwindow* f_win;
			int f_width;
			int f_height;
			const char* f_title;
			bool f_fullscreen;
			bool f_keys[GLFW_KEY_LAST];
			bool f_mouseButtons[GLFW_MOUSE_BUTTON_LAST];
			double f_xpos;
			double f_ypos;

		public:
			f_Window(int width, int height, const char* title);
			f_Window(int width, int height, const char* title, const bool fullscreen);
			f_Window();
			~f_Window();

			int init(); // Returns 0 if init was successful. Otherwise returns 1.
			void setWidth(int width){f_width = width;}
			void setHeight(int height){f_height = height;}
			void toggleFullscreen(){f_fullscreen = !f_fullscreen;}
			void activateFullscreen();

			int getWidth(){return f_width;}
			int getHeight(){return f_height;}
			GLFWwindow* getWindowPointer(){return f_win;}

			void update();
			void clear();
			bool close();

			bool isKeyPressed(unsigned int key)const ;
			bool isMouseButtonPressed(unsigned int button)const ;
			void getCursorPosition(double* x, double* y)const ;

			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	};
}
