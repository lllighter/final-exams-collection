#include "arrayStack.h"
#include <stdlib.h>
#include <stdio.h>
// 新建一个容量为capacity的数组来存储堆栈
stack aCreate(int capacity )
{
	stack s;
	s.buffer = (element *)malloc(sizeof(element)*capacity);
	s.capacity = capacity;
	s.top = -1;
	return s;
}
// 判断堆栈是否为满，如果为空返回-1，否则返回0
int aIsFull(stack s)
{
	return s.top == s.capacity-1;
}
// 判断堆栈是否为空，如果为空返回-1，否则返回0
int aIsEmpty(stack s)
{
	return s.top == -1;
}
void astackFull()
{
	printf("ERROR:stack is full");
	exit(0);
}
// 入栈
void apush(stack *s, element item)
{
	if(!aIsFull(*s)){
		(*s).buffer[++(*s).top] = item;
	}
	else
		return astackFull();
}
element astackEmpty()
{
	printf("ERROR:stack is empty");
	exit(0);
}
// 出栈
element apop(stack *s)
{
	element temp;
	if(!aIsEmpty(*s)){
		temp = (*s).buffer[(*s).top--];
		return temp;
	}
	else
		return astackEmpty();
}