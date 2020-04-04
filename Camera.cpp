#include "Camera.h"
Camera::Camera(float x, float y, float z,float w,float h,float l)
{
	this->rect.x = x;
	this->rect.y = y;
	this->rect.z = z;
	this->width = w;
	this->height = h;
	this->leght = l;
}
Camera::~Camera()
{

}
void Camera::MoveUpDown(float detal_moving, float lx, float lz)
{
	this->rect.x += detal_moving * lx;
	this->rect.z += detal_moving * lz;
}
