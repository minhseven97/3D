#pragma once
#include "comHeader.h"
#include "BasicCad.h"
#include "Texture.h"


class Sky : public BaseObject
{
private:
	Texture* _texture;
	GLuint _box;
public:
	Sky(float width, float leght, float height, int x, int y, int z, Texture* texture);
	~Sky();
	
	void CreateSky();

};

