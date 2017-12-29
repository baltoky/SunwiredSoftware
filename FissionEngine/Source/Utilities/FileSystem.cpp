#include "FileSystem.h"

namespace Fission
{
	void writeFile(bool append, const char* filepath, const char* stringToWrite){
		std::string w;// To open file as write or append
		if(append) w = "a";
		else w = "w";
		FILE* fp = fopen(filepath, (const char*)w.c_str());
		fputs(stringToWrite, fp);
		fclose(fp);
	}

	int getFileSize(const char* filepath){
		FILE* fp = fopen(filepath, "r");
		int size = 0;
		while(fgetc(fp) != EOF){
			size++;
		}
		fclose(fp);
		return size;
	}

	char* getString(const char* filepath, int begin, int end){
		int size = getFileSize(filepath);
		if(end > size){
			end = size;
		}
		int bufferSize = end - begin;
		FILE* fp = fopen(filepath, "r");
		char* buffer = new char[bufferSize];
		fseek(fp, begin, SEEK_SET);
		for(int i  = 0; i < bufferSize; i++){
			fscanf(fp, "%c", &buffer[i]);
		}
		fclose(fp);
		return buffer;
	}
}
