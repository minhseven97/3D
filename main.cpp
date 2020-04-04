#include "comHeader.h"
#include "BasicCad.h"
#include "Texture.h"
#include "Building.h"
#include "Camera.h"
#include  "OBJModel.h"

#pragma comment(lib,"legacy_stdio_definitions.lib")

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

#define K_MAT_RED   0
#define K_MAT_GREEN 1
#define K_MAT_BLUE  2
#define K_MAT_YELLOW 3
#define K_MAT_PINK  4
#define K_MAT_WHITE 10
#define NUM_BUILDING 10

#define  DIS_CAM_TO_MODE 10
#define  GROUND_SIZE 1000
#define  CAMERA_FAR 1200

GLuint g_ground;
GLuint g_box;                          // sử dụng để tạo display list cho đối tượng.

Rect old_rect_cam;
float old_rect_cam_y;
//======================================================
char brics_bmp[100] = { "brics.bmp" }; // lưu trữ tên file texture
char Ground_bmp[100] = { "ground1.bmp" };
char Building_bmp[100] = { "car.bmp" };
char s[] = { "test.obj" };


float lx = 0.0;
float lz = -1.0;
float centerY = 10.0;
float angle = 0.0;
float deltaAngleX = 0.0f;
int xOrigin = -1;
float detal_moving = 0.0;
float detal_angle = 0.0;
int xx = 400;
int zz = -200;
Reader obj;

float angle_obj;
//================================= class Texture =======================================
Texture* texture1;
Texture* texture2;
//================================= class Building ======================================
std::vector<Building*>list_building;
//================================= class Camera ======================================
Camera* cam;
//=======================================================================================
Building::Building(float width, float leght, float height, int x, int y, int z, Texture* texture)
{
	this->width = width;
	this->leght = leght;
	this->height = height;
	this->rect.x = x;
	this->rect.y = y;
	this->rect.z = z;
	this->_texture = texture;
	this->_box = NULL;
}
Building::~Building()
{

}
void Building::CreateBuilding()
{
	_box = BasicCad::MakeBox(leght, width, height);
	glPushMatrix();
	glTranslatef(xx, rect.y, zz);
	glEnable(GL_TEXTURE_2D);
	_texture->Bin();
	glCallList(_box);
	_texture->UnBin();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
/////////////////
void SetMaterialColor(GLfloat ambient[4], GLfloat diff_use[4])
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}
//===============================Hàm ét mầu cho vật liệu========================================================
void SetMaterialColor(const int& type)
{
	GLfloat ambien[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diff_use[] = { 0.0, 0.0, 0.0, 1.0 };
	switch (type)
	{
	case K_MAT_RED:
	{
		ambien[0] = 1.0f;
		diff_use[0] = 1.0f;
	}
	break;
	case K_MAT_GREEN:
	{
		ambien[1] = 1.0f;
		diff_use[1] = 1.0f;
	}
	break;
	case K_MAT_BLUE:
	{
		ambien[2] = 1.0f;
		diff_use[2] = 1.0f;
	}
	break;
	case K_MAT_YELLOW:
	{
		ambien[0] = 1.0f;
		ambien[1] = 1.0f;
		diff_use[0] = 1.0f;
		diff_use[1] = 1.0f;
	}
	break;
	case K_MAT_PINK:
	{
		ambien[0] = 1.0f;
		ambien[2] = 1.0f;
		diff_use[0] = 1.0f;
		diff_use[1] = 1.0f;
	}
	break;
	case K_MAT_WHITE:
	default:
	{
		ambien[0] = 1.0f;
		ambien[1] = 1.0f;
		ambien[2] = 1.0f;
		diff_use[0] = 1.0f;
		diff_use[1] = 1.0f;
		diff_use[2] = 1.0f;
	}
	break;
	}

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambien);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
}
//================================= Hàm vẽ tọa độ ======================================================
void DrawCoordinate()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	glEnable(GL_LIGHTING);
}

//=================================== Phần sử lý bàn phím ======================================
void OnKeyUp(unsigned char ch, int x, int y)
{
	switch (ch)
	{
	case 'A':
		xx -= 5;
		break;
	case 'a':
		xx -= 5;
		break;
	case 'S':
		zz += 5;
		break;
	case 's':
		zz += 5;
		break;
	case 'D':
		xx += 5;
		break;
	case 'd':
		xx += 5;
		break;
	case 'W':
		zz -= 5;
		break;
	case 'w':
		zz -= 5;
		break;
	default:
		break;
	}
}

void OnKeyDown(unsigned char ch, int x, int y)
{
	switch (ch)
	{
	case 'A':
		break;
	case 'a':
		break;
	case 'S':
		break;
	case 's':
		break;
	case 'D':
		break;
	case 'd':
		break;
	case 'W':
		break;
	case 'w':
		break;
	default:
		break;
	}
}
void OnSpecialKeyDown(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		detal_moving = 0.5;
		break;
	}
	case GLUT_KEY_DOWN:
	{
		detal_moving = -0.5;
		break;
	}
	case GLUT_KEY_LEFT: // down
	{
		cam->setY_Down(4.0);
		centerY -= 4;
		break;
	}
	case GLUT_KEY_RIGHT:// up
	{
		cam->setY_Up(4.0);
		centerY += 4;
		break;
	}
	default:
		break;
	}
}

void OnSpecialKeyUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
	case GLUT_KEY_UP:
	{
		detal_moving = 0.0f;
		break;
	}
	case GLUT_KEY_LEFT:
	case GLUT_KEY_RIGHT:
	{
		detal_angle = 0.0;
		break;
	}
	default:
		break;
	}
}
//================================ Xử lý chuột ===================================
void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) 
	{

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngleX;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
	
}
void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngleX = (x - xOrigin) * 0.002f;

		// update camera's direction
		lx = sin(angle + deltaAngleX);
		lz = -cos(angle + deltaAngleX);
	}
}
//==================================================================================================
bool CheckCollision(BaseObject* obj1, BaseObject* obj2)
{
	bool collision = false;
	float x1, y1, z1;
	float x2, y2, z2;
	// định nghĩa lại tọa độ của đối tượng, là tâm của đối tượng
	// object 1:
	x1 = obj1->getRect().x + obj1->getLeght() * 0.5;
	y1 = obj1->getRect().y + obj1->getHeight() * 0.5;
	z1 = obj1->getRect().z + obj1->getWidth() * 0.5;
	//object 2:
	x2 = obj2->getRect().x + obj2->getLeght() * 0.5;
	y2 = obj2->getRect().y + obj2->getHeight() * 0.5;
	z2 = obj2->getRect().z + obj2->getWidth() * 0.5;
	
	if (
		(x2 > (x1 - obj1->getLeght() * 0.5 - obj2->getLeght() * 0.5) && x2 < (x1 + obj1->getLeght() * 0.5 + obj2->getLeght() * 0.5)) &&
		(y2 > (y1 - obj1->getHeight() * 0.5 - obj2->getHeight() * 0.5) && y2 < (y1 + obj1->getHeight() * 0.5 + obj2->getHeight() * 0.5)) &&
		(z2 > (z1 - obj1->getWidth() * 0.5 - obj2->getWidth() * 0.5) && z2 < (z1 + obj1->getWidth() * 0.5 + obj2->getWidth() * 0.5))
		)
		{
			collision = true;
		}
	else
		{
			collision = false;
		}
	return collision;
}
//================================== Hàm sử lý hiển thị lên màn hình ===============================
void RenderScene()
{	
	if (detal_moving != 0.0)
		cam->MoveUpDown(detal_moving, lx, lz);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5, 5, -5, 5, 5, CAMERA_FAR);
	gluLookAt(cam->getRectCam().x, cam->getRectCam().y, cam->getRectCam().z, cam->getRectCam().x + lx, centerY, cam->getRectCam().z + lz, 0.0, 1.0, 0.0);

	glPushMatrix();
	DrawCoordinate();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5 * GROUND_SIZE, 0.0, -0.5 * GROUND_SIZE);
	glEnable(GL_TEXTURE_2D);
	texture1->Bin();
	glCallList(g_ground);
	texture1->UnBin();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	//============== set older camera position ================
	old_rect_cam = cam->getRectCam();
	old_rect_cam_y = cam->getRectCam().y;
	//Render building
	for (int i = 0; i < list_building.size(); i++)
	{
		Building* building = list_building.at(i);
		if (building != NULL)
		{
			building->CreateBuilding();
			if (CheckCollision(building, cam)==true)
			{
				cam->setRect(old_rect_cam.x-2,old_rect_cam.y,old_rect_cam.z-2);
				//detal_moving = 0.0;
			}
		}
	}
	//set camera condition on ground
	if (cam->getRectCam().y <= 0.0)
	{
		cam->setRect(cam->getRectCam().x, old_rect_cam_y + 10, cam->getRectCam().z);
		centerY += 10;
	}
	/*obj.draw(s);

	glutSwapBuffers();
	angle += .1f;*/
	glFlush();
	glutPostRedisplay();
}
//=================== Hàm tạo đối tượng building
std::vector<Building*> MakeBuilding()
{
	std::vector<Building*> list_building;
	Building* building[NUM_BUILDING];
	building[1] = new Building(35, 35, 35, 400, 0, -200, texture2);
	list_building.push_back(building[1]);
	/*building[2] = new Building(175, 80, 80, 110, 0, 0, texture1);
	list_building.push_back(building[2]);*/
	return list_building;
}
//=================== Hàm khởi tạo
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	
	/*AllocConsole();
	obj.load(s);
*/
	GLfloat light_pos[] = { 1.0, 1.0, 1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);

	// initialzation texture class
	texture1 = new Texture(Ground_bmp, GL_TEXTURE_2D);
	texture2 = new Texture(Building_bmp, GL_TEXTURE_2D);

	//initialzation building class
	list_building = MakeBuilding();
	//initialzation camera class
	cam = new Camera(0.0, 10.0, 30.0,10,10,10);
	//initialzation background
	g_ground = BasicCad::MakeBox(GROUND_SIZE, GROUND_SIZE, 0.5);

}
//========================= Hàm sét màn hình, khi có sự thay đổi
void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float ratio = (float)width / (float)height;
	gluPerspective(45.0, ratio, 1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
//=============================================================

//=============================================================
void main()
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(150, 150);
	glutCreateWindow("Opengl Study");

	Init();
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);
	glutKeyboardFunc(OnKeyDown);
	glutKeyboardUpFunc(OnKeyUp);
	glutSpecialFunc(OnSpecialKeyDown);
	glutSpecialUpFunc(OnSpecialKeyUp);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	//glutMouseWheelFunc(mouseWheel);
	glutMainLoop();
}