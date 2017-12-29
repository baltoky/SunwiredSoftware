#ifndef LOG_SYSTEM_H
#define LOG_SYSTEM_H

#include <iostream>

#define LOG(x) \
	std::cout << x << "\n" << \
	"l: " << __LINE__ << "\n" << \
	"f: " << __FILE__ << std::endl

#endif
