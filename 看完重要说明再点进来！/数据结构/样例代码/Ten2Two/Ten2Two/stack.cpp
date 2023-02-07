
#include "stdafx.h"
#include "stack.h"
#include <stdlib.h>
#define MALLOC(p,s) \
	if(!((p)=(stackPointer)malloc(s))){ \
	fprintf(stderr, "Insufficient memory"); \
	exit(EXIT_FAILURE);\
	}
//新建第i个堆栈，如果该堆栈非空，需要清空该堆栈

extern stackPointer top[MAX_STACKS] ;

void Create(int i)
{
	top[i] = NULL;
	// todo
}
//判断第i个堆栈是否为满
int IsFull(int i)
{
	return 0;
}
//将元素item入第i个堆栈
void Push(int i, element item)
{
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}
//判断第i个堆栈是否为空
int IsEmpty(int i)
{
	return top[i]==NULL;
}
element stackEmpty()
{
	element item;
	item.key = -1;
	return item;
}
//从第i个堆栈出栈
element Pop(int i)
{
	stackPointer temp  = top[i];
	element item;
	if(!temp)
		return stackEmpty();
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;

}
