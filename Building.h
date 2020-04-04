#pragma once
#include "comHeader.h"
#include "BasicCad.h"
#include "Texture.h"


class Building: public BaseObject
{
private:
	Texture* _texture;
	GLuint _box;
public:
	Building(float width, float leght, float height, int x, int y, int z, Texture* texture);
	~Building();
	void CreateBuilding();

};

