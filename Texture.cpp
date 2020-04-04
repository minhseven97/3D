#include "Texture.h"
Texture::Texture(const char* fileName, GLenum type)
{
	this->type = type;

	AUX_RGBImageRec* texture_image = NULL;

	if (texture_image = LoadBMP(fileName))
	{

		// Bắt đầu quá trình gen texture.
		glGenTextures(1, &this->id);
		glBindTexture(this->type, this->id);

		glTexParameteri(this->type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(this->type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//map dữ liệu bit map vào texture.
		glTexImage2D(this->type, 0, 3, texture_image->sizeX, texture_image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_image->data);
	}
	else
	{
		if (texture_image)
		{
			if (texture_image->data)
				free(texture_image->data);
			free(texture_image);
		}
	}
}
Texture::~Texture()
{
	glDeleteTextures(1, &this->id);
}
AUX_RGBImageRec* Texture::LoadBMP(const char* Filename)
{
	FILE* File = NULL;

	if (!Filename)
		return NULL;
	fopen_s(&File, Filename, "r");
	if (File)
	{
		fclose(File);
		return auxDIBImageLoadA((LPCSTR)Filename);
	}
	return NULL;
}
void Texture::Bin()
{
	glBindTexture(this->type, this->id);
}
void Texture::UnBin()
{
	glBindTexture(this->type, 0);
}
