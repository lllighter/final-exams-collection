#include "BinaryTree.h"

typedef treePointer element;

// 定义了一个堆栈的结构体
typedef struct {
	element *buffer;  // 用来放元素的数组
	int capacity;     // 数组的容量
	int top;          // 堆栈栈顶的位置
} stack;

stack Create(int capacity); // 初始化堆栈
int IsFull(stack s);  // 判断第i个数组是否为满
int IsEmpty(stack s); // 判断第i个数组是否为空
element Pop(stack *s);
void Push(stack *s, element item);
