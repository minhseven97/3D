#pragma once
#include "comHeader.h"
#include "BasicCad.h"
#include "Texture.h"


class Xemay : public BaseObject
{
private:
	Texture* _texture;
	GLuint _box;
public:
	 Xemay(float width, float leght, float height, int x, int y, int z, Texture* texture);
	~Xemay();
	void CreateXemay();

};

