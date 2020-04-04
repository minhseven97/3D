#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>
//#include <glm.hpp>
#include <map>

#include <gl/glut.h>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <gl/GLAUX.H>
#pragma comment(lib,"legacy_stdio_definitions.lib")


struct Rect {
	float x;
	float y;
	float z;
};

class BaseObject
{
protected:
	float width;
	float leght;
	float height;
	Rect rect;
public:
	float getWidth() { return width; }
	float getLeght() { return leght; }
	float getHeight() { return height; }
	void setWithHeightLeinght(float w, float h, float l) { width = w; height = h; leght = l; }

	Rect getRect() { return rect; }
	void setRect(float x,float y,float z) {
		this->rect.x = x;
		this->rect.y = y;
		this->rect.z = z;
	}
};