#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Fission{
	class f_Window{
		private:
			GLFWwindow* f_win;
			unsigned short f_width;
			unsigned short f_height;

		public:
			f_Window(unsigned short width, unsigned short height) const width = 800, const height = 500;
			~f_Window();

			init();
	};
}
