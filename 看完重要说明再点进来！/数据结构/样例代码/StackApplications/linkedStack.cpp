#include "linkedStack.h"
#include <stdlib.h>
#include <stdio.h>
// 新建带一个头结点的单链表（stack)
stackPointer Create(void )
{
	stackPointer top = NULL;
	// 申请头结点
	top = (stackPointer)malloc(sizeof(stack));
	top->link = NULL;
	return top;
}
// 判断堆栈是否为满，如果为空返回-1，否则返回0
int IsFull(stackPointer top)
{
	return 0;
}
// 判断堆栈是否为空，如果为空返回-1，否则返回0
int IsEmpty(stackPointer top)
{
	return top->link==NULL;
}
// 入栈
void push(stackPointer top, element item)
{
	stackPointer temp;
	temp = (stackPointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = top->link;
	top->link = temp;
}

element stackEmpty()
{
	printf("ERROR: stack is empty.");
	exit(0);
}

// 出栈
element pop(stackPointer top)
{
	stackPointer temp = top->link;
	element item;
	if (!temp)
		return stackEmpty();
	item = temp->data;
	top->link = temp->link;
	free(temp);
	return item;
}

