#pragma once

#ifndef __STACK__
#define __STACK__

#define MAX_STACKS 10
typedef struct{
	int key;
}element;
typedef struct stack *stackPointer;
typedef struct stack{
	element data;
	stackPointer link;
};

//新建第i个堆栈，如果该堆栈非空，需要清空该堆栈
void Create(int i);
//判断第i个堆栈是否为满
int IsFull(int i);
//将元素item入第i个堆栈
void Push(int i, element item);
//判断第i个堆栈是否为空
int IsEmpty(int i);
//从第i个堆栈出栈
element Pop(int i);

#endif
