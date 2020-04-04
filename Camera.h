#pragma once
#include "comHeader.h"


class Camera:public BaseObject
{
public:
	Camera(float x,float y,float z,float w,float h,float l);
	~Camera();
	Rect getRectCam() { return rect; }
	
	void setY_Down(float y) { rect.y -= y; }
	void setY_Up(float y) { rect.y += y; }

	void MoveUpDown(float detal_moving, float lx, float lz);
};

