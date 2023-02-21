
#define MAX_STACKS 10
typedef struct {
	int key;
}element;
typedef struct stack *stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
};

// 新建带一个头结点的单链表
stackPointer Create();
// 判断堆栈是否为满，如果为空返回-1，否则返回0
int IsFull(stackPointer top);
// 判断堆栈是否为空，如果为空返回-1，否则返回0
int IsEmpty(stackPointer top);
// 入栈
void push(stackPointer top, element item);
// 出栈
element pop(stackPointer top);

