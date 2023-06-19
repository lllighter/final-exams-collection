

#include <gl/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "math.h"
#include "Polygon.h"


int defSCREEN_WIDTH = 600, defSCREEN_HEIGHT = 600;
int g_iCtrlPntNum;
wcPt2D *g_pCtrlPoints;
bool g_bPointMoving;	//按下空格键选择一个顶点，该变量被置为true
bool g_bFinish;			//按下'm'键，结束顶点的选择，该变量被置为true

void Display();
void Reshape(int w,int h);
void Keyboard(unsigned char uchKey, int iXPos, int iYPos);
void PassiveMotionFunc(int iXPos, int iYPos);
void MyInit(void);
void SetPixel(int x, int y);
void BresLine(int x0,int y0,int x1,int y1,void (*setPixel)(int x,int y));

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	MyInit();
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(defSCREEN_WIDTH,defSCREEN_HEIGHT);

	int windowHandle = glutCreateWindow( "Glut DrawPolygon");
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutPassiveMotionFunc(PassiveMotionFunc);

	glutMainLoop();
	if (g_pCtrlPoints)
	{ 
		free(g_pCtrlPoints);
	}
	return 0;
}

void SetPixel(int x, int y)
{
	glPointSize(1.0);
	glColor3f(0.0,0,1.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
void Display()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	int line_count;
	if (g_bPointMoving)	//正在移动鼠标，需要实时画移动的点，线数=顶点数
		line_count = g_iCtrlPntNum;
	else				//否则，线数=顶点数-1
		line_count = g_iCtrlPntNum-1;	
	for(int i=0;i< line_count;i++)
	{
		BresLine(g_pCtrlPoints[i].x,g_pCtrlPoints[i].y,g_pCtrlPoints[i+1].x,g_pCtrlPoints[i+1].y,SetPixel);//画出多边形轮廓线
	}	
	if (g_bFinish)
	{
		//调用多边形扫描转换算法对选定的区域填充红色
		//请同学们实现DrawPolygonOpenGL函数和 DrawPolygon函数
		// DrawPolygonOpenGL(g_iCtrlPntNum, g_pCtrlPoints);
		DrawPolygon(g_iCtrlPntNum, g_pCtrlPoints);
	 }
	glFlush();
}
void Keyboard(unsigned char uchKey, int iXPos, int iYPos)
{
	if(iXPos<0||iXPos>=defSCREEN_WIDTH||iYPos<0||iYPos>=defSCREEN_HEIGHT)
		return;

	if(uchKey == 27/*Esc*/) {
		exit(0);
	}
	else if(uchKey==' '){//空格键选择一个顶点

		if(g_bFinish){//当所有顶点都已选择完，按下空格键，重新选择顶点集
			g_iCtrlPntNum = 0;
			g_bFinish = false;
		}

		if(g_iCtrlPntNum>=99)//过多的顶点，会导致计算值过大，甚至超出计算机所能表示的数的上限
			return;

		//设置新的顶点坐标
		g_pCtrlPoints[g_iCtrlPntNum].x = iXPos;
		g_pCtrlPoints[g_iCtrlPntNum].y = defSCREEN_HEIGHT - iYPos;
		g_iCtrlPntNum++;//顶点数加1

		g_bPointMoving = false;

	}
	else if(uchKey=='m'||uchKey=='M'){//结束顶点的选择

		if(!g_bFinish){
			//顶点数不变，重新设置曲线相关属性值
			g_pCtrlPoints[g_iCtrlPntNum].x = g_pCtrlPoints[0].x;
			g_pCtrlPoints[g_iCtrlPntNum].y = g_pCtrlPoints[0].y;
			g_iCtrlPntNum++;//顶点数加1
			g_bFinish = true;
			g_bPointMoving = false;
		}
	}
	
	glutPostRedisplay();
}
void Reshape(int w,int h)
{
	defSCREEN_WIDTH = w;
	defSCREEN_HEIGHT = h;
	glViewport(0.0,0.0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,w,0.0,h,1,-1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void MyInit(void)
{
	g_iCtrlPntNum = 0;
	g_pCtrlPoints = (wcPt2D*)malloc(100*sizeof(wcPt2D));
	g_bFinish = false;
	g_bPointMoving = false;
}
void PassiveMotionFunc(int iXPos, int iYPos)
{
	if(!g_bFinish){//如果没有完成顶点的选择
		//实时保存光标位置
		g_pCtrlPoints[g_iCtrlPntNum].x = iXPos;
		g_pCtrlPoints[g_iCtrlPntNum].y = defSCREEN_HEIGHT - iYPos;

		if(!g_bPointMoving){//如果刚刚选择了一个顶点,当前的光标位置还不能成为新的顶点，但应该显示到屏幕上，以实现"拖动"的效果
			g_bPointMoving = true;
		}
	}
	glutPostRedisplay();
}

int Sign(int x)
{
	if (x >= 0) return 1;
	else  return -1;
}
void BresLine(int x0,int y0,int x1,int y1,void (*setPixel)(int x,int y)){

	int x,y,dx,dy,s1,s2,Interchange,Temp,e;
	x = x0; y = y0;
	dx = abs(x1 - x0);dy = abs(y1 - y0);
	s1 = Sign(x1 - x0); s2 = Sign(y1 - y0);
	if (dy > dx) {Temp = dx;dx = dy; dy = Temp;Interchange = 1;}
	else Interchange = 0;
	e = 2 * dy - dx;
	for (int i = 1;i <= dx;i++)
	{
		setPixel(x,y);
		while (e > 0)
		{
			if (Interchange == 1) x = x + s1;
			else  y = y + s2;
			e = e - 2 * dx;
		}
		if (Interchange == 1) y = y + s2;
		else x = x + s1;
		e = e + 2 *dy;
	}
}

