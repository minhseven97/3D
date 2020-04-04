#pragma once
#include "comHeader.h"
class Texture
{
private:
	GLuint id;
	unsigned int type;
public:
	Texture(const char* fileName, GLenum type);
	~Texture();
	GLuint getID() const { return this->id; }

	AUX_RGBImageRec* LoadBMP(const char* Filename);
	void Bin();
	void UnBin();
};

