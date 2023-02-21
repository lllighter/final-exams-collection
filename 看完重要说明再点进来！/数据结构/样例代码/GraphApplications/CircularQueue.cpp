#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

circular_queue CreateQueue(int capacity)
{
	circular_queue newqueue;
	newqueue.queue = (element *)malloc(sizeof(element)*capacity);
	newqueue.capacity = capacity;
	newqueue.front = newqueue.rear = 0;
	return newqueue;
}

int IsQueueEmpty(circular_queue queue)
{
	return queue.front == queue.rear;
}

int IsQueueFull(circular_queue queue)
{
	return (queue.rear + 1)%queue.capacity == queue.front;
}

int EnQueue(circular_queue *queue, element item)
{
	if(!IsQueueFull(*queue)){
		(*queue).rear = ((*queue).rear+1) % (*queue).capacity;
		(*queue).queue[(*queue).rear] = item;
		return TRUE;
	}
	return FALSE;
}

int DeQueue(circular_queue *queue, element *item)
{
	if(!IsQueueEmpty(*queue)){
		(*queue).front = ((*queue).front+1) % (*queue).capacity;
		*item = (*queue).queue[(*queue).front];
		return TRUE;
	}
	return FALSE;
}