#ifndef IMAGE_H
#define IMAGE_H

#include"glfw3.h" 
#include "stb_image.h"

class Image
{
private:
	unsigned int m_Image;
	const char* m_Path;
	int m_Width, m_Height, m_Channel;
public:
	Image()=default;
	Image(const char* _path);
	~Image();

	void Open(const char* _path);
	unsigned int GetRendererID();
	int GetWidth();
	int GetHeight();
	int GetChannel();

	void Bind();
	void UnBind();
};
#endif