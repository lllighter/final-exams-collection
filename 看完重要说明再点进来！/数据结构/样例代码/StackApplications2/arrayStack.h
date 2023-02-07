
typedef struct {
	int key;
}element;

typedef struct {
	element *buffer;  // 动态数组
	int capacity; // 数组的容量
	int top;  // 栈顶所在位置
} stack;

// 新建一个容量为capacity的数组来存储堆栈
stack aCreate(int capacity );
// 判断堆栈是否为满，如果为空返回-1，否则返回0
int aIsFull(stack s);
// 判断堆栈是否为空，如果为空返回-1，否则返回0
int aIsEmpty(stack s);
// 入栈
void apush(stack *s, element item);
// 出栈
element apop(stack *s);