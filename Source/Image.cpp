#include"Image.h"

Image::~Image()
{
	glDeleteTextures(GL_TEXTURE_2D, &m_Image);
}

void Image::Open(const char* _path)
{
	glGenTextures(1, &m_Image);
	Bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	int width, height, channel;
	unsigned char* data = stbi_load(_path, &width, &height, &channel, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, (channel == 3 ? GL_RGB : GL_RGBA), width, height, 0, (channel == 3 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, data);
	if (data)
		stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);

	m_Path = _path;
	m_Width = width;
	m_Height = height;
	m_Channel = channel;
}

unsigned int Image::GetRendererID()
{
	return m_Image;
}

int Image::GetWidth()
{
	return m_Width;
}

int Image::GetHeight()
{
	return m_Height;
}

int Image::GetChannel()
{
	return m_Channel;
}

void Image::Bind()
{
	glBindTexture(GL_TEXTURE_2D,m_Image);
}

void Image::UnBind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
