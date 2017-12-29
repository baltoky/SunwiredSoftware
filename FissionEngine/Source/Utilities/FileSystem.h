#ifndef FIS_FILE_SYSTEM
#define FIS_FILE_SYSTEM

#include <cstdlib>
#include <cstdio>
#include <string>

namespace Fission
{
	void writeFile(bool append, const char* filepath, const char* stringToWrite);
	int getFileSize(const char* filepath);
	char* getString(const char* filepath, int begin, int end);
}

#endif
