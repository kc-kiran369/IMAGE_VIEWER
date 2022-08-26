#ifndef FILE_DIALOG_H
#define FILE_DIALOG_H

#include<string>


#include<GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include<GLFW/glfw3native.h>

class FileDialog
{
public:
	static std::string OpenFile(const char* filters, GLFWwindow* window);
	static std::string SaveFile(const char* filters, GLFWwindow* window);
};

#endif
