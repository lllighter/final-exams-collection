#ifndef POLYGON_H


#include "common.h"
//边结点类型
struct EdgeNode;
typedef struct EdgeNode *EdgeNodePointer;
typedef struct EdgeNode{
	int ymax;
	float xmin;
	float dx;
	EdgeNodePointer next;
};
void DrawPolygon(int g_iCtrlPntNum, wcPt2D	g_pCtrlPoints[]);
void DrawPolygonOpenGL(int g_iCtrlPntNum, wcPt2D	g_pCtrlPoints[]);

#endif