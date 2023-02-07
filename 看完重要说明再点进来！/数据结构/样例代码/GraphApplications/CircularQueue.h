typedef int element;
typedef struct circular_queue{
	element *queue;
	int capacity;
	int front;
	int rear;
};

circular_queue CreateQueue(int capacity);
int IsQueueEmpty(circular_queue queue);
int IsQueueFull(circular_queue queue);
int EnQueue(circular_queue *queue, element item);
int DeQueue(circular_queue *queue, element *item);

