#include <stdio.h>
#include <stdlib.h>
#include "arrayStack.h"

// 初始化堆栈
stack Create(int capacity)
{
	stack s;
	element *buffer = (element *)malloc(sizeof(element)*capacity);
	s.buffer = buffer;
	s.capacity = capacity;
	s.top = -1;
	return s;
}
// 判断第i个数组是否为满
int IsFull(stack s)
{
	return s.top == s.capacity-1;
}
// 判断第i个数组是否为空
int IsEmpty(stack s)
{
	return s.top == -1;
}
element stackEmpty(void )
{
	return NULL;
}
element Pop(stack *s)
{
	if(!IsEmpty(*s)){
		element temp;
		temp = (*s).buffer [(*s).top--];
		return temp;
	}
	else
		stackEmpty();
}
element stackFull(void )
{
	printf("ERROR: stack is full");
	exit(0);
}
void Push(stack *s, element item)
{
	if(!IsFull(*s)){
		(*s).buffer[++(*s).top] = item;
	}
	else
		stackFull();
}