#include <gl/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "Polygon.h"
#include "common.h"
#include "math.h"

struct vertex { 
    float ver_x;
    float ver_y;
};
typedef struct XET { 
    float x;
    float dx, ymax;
    XET* next;
}AET, NET;

vertex* ver;
//存放有关多边形扫描转换的函数

//用OpenGL方法绘制多边形
void DrawPolygonOpenGL(int g_iCtrlPntNum, wcPt2D	g_pCtrlPoints[])
{
	 glColor3f(1.0,0,0.0);
	//在此填写代码，可能也需要增加其它函数
	 glShadeModel(GL_SMOOTH);
	 glClear(GL_COLOR_BUFFER_BIT);
	 glBegin(GL_POLYGON);
	 for (int i = 0; i < g_iCtrlPntNum; i++) {
		 glVertex2f(g_pCtrlPoints[i].x, g_pCtrlPoints[i].y);
	 }
	 glEnd();
	 glFlush();
}


//请同学们实现DrawPolygon函数，完成多边形的扫描转换算法
//同时也要实现边表和活化边表的数据结构与相应算法
//顶点数存于g_iCtrlPntNum，顶点坐标值存于g_pCtrlPoints数组中
//!!!注意!!!：按M键结束选择后，最后一个顶点 等于 第一个顶点，
//即g_pCtrlPoints[g_iCtrlPntNum-1] 与 g_pCtrlPoints[0]是相同的
//以四边形为例，g_iCtrlPntNum=5，起点g_pCtrlPoints[0]与终点g_pCtrlPoints[4]指同一个点
//DrawPolygon就是PPT上的FillPolygonbyAET函数，最好用PPT上算法实现
void DrawPolygon(int g_iCtrlPntNum, wcPt2D	g_pCtrlPoints[])
{
	//在此填写代码，可能也需要增加其它函数
    int MaxY = 0;
    int i, n = g_iCtrlPntNum;
    ver = (vertex*)malloc(sizeof(vertex) * n);

    for (int i = 0; i < n; i++) {
        ver[i].ver_x = g_pCtrlPoints[i].x;
        ver[i].ver_y = g_pCtrlPoints[i].y;
    }
    for (i = 0; i < n; i++) {
        if (ver[i].ver_y > MaxY)
            MaxY = ver[i].ver_y;
    }

    AET* pAET = new AET;
    pAET->next = NULL;

    NET* pNET[1024];
    for (i = 0; i <= MaxY; i++) {
        pNET[i] = new NET;
        pNET[i]->next = NULL;
    }


    for (i = 0; i < MaxY; i++) {
		for (int j = 0; j < n; j++) {
            if (ver[j].ver_y == i) {
                if (ver[(j + 1 + n) % n].ver_y > ver[j].ver_y) {
                    NET* p = new NET;
                    p->x = ver[j].ver_x;
                    p->ymax = ver[(j + 1 + n) % n].ver_y;
                    p->dx = (ver[(j + 1 + n) % n].ver_x - ver[j].ver_x) / (ver[(j + 1 + n) % n].ver_y - ver[j].ver_y);
                    p->next = pNET[i]->next;
                    pNET[i]->next = p;
                }
                if (ver[(j - 1 + n) % n].ver_y > ver[j].ver_y) {
                    NET* p = new NET;
                    p->x = ver[j].ver_x;
                    p->ymax = ver[(j - 1 + n) % n].ver_y;
                    p->dx = (ver[(j - 1 + n) % n].ver_x - ver[j].ver_x) / (ver[(j - 1 + n) % n].ver_y - ver[j].ver_y);
                    p->next = pNET[i]->next;
                    pNET[i]->next = p;
                }
            }
        }
    }
    for (i = 0; i <= MaxY; i++) {
        AET* p = new AET;
        p = pAET->next;
        AET* n = new AET;
        if (pNET[i]->next && pNET[i]->next->next) {
            if (pNET[i]->next->dx > 0) {
                NET* t = new NET;
                t = pNET[i]->next;
                n = pNET[i]->next->next;
                t->next = NULL;
                n->next = NULL;
                pNET[i]->next = n;
                n->next = t;
            }
        }
        while (p) {
            p->x = p->x + p->dx;
            p = p->next;
        }
        p = pAET->next;
        n = pAET;
        while (p) {
            if (p->ymax == i) {
                n->next = p->next;
                free(p);
                p = n->next;
            }
            else {
                p = p->next;
                n = n->next;
            }
        }
        p = pAET->next;
        n = pAET;
        NET* a = new NET;
        a = pNET[i]->next;
        if (a) {
            NET* b = new NET;
            b = a;
            while (b->next) {
                b = b->next;
            }
            if (!pAET->next) {
                pAET->next = a;
            }
            else {
                while (p) {
                    if (a->x < p->x) {
                        b->next = p;
                        n->next = a;
                        break;
                    }
                    if (!p->next) {
                        p->next = a;
                        break;
                    }
                    n = n->next;
                    p = p->next;
                }
            }
		}
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0, 0.0);
        glBegin(GL_POINTS);
        p = pAET->next;
        while (p && p->next) {
            for (float j = p->x; j <= p->next->x; j++)
                glVertex2i(static_cast<int>(j), i);
            p = p->next->next;
        }

    }
    glEnd();
    glFlush();
}