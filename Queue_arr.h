#include <stdio.h>
#include <stdlib.h>
#include "Boolean.h"
#include <string.h>
#define NAME 20
typedef char* Element;
typedef struct{
	Element*queue;
	int size;
	int front,rear;
}Queue;
Queue*CreatQueue(int size)
{
	Queue*pQueue=(Queue*)malloc(sizeof(Queue));
	if(pQueue==NULL)
	return NULL;
	
	pQueue->queue=(Element*)malloc(size*sizeof(Element));
	if(pQueue->queue==NULL){
	free(pQueue);
	return NULL;
	}
	pQueue->size=size;
	pQueue->front=0;
	pQueue->rear=0;
	
	return pQueue;
}
Boolean IsFullQueue(Queue*q)
{
	if(q->front==q->rear+1)
		return TRUE;
	else return FALSE;
}
void Enqueue(Queue*q,Element item)
{	
	if(IsFullQueue(q))
		puts("Queue is Full");
	else{
		q->rear=(q->rear+1)%(q->size);
		q->queue[q->rear]=(char*)malloc(sizeof(char)*NAME);
		strcpy(q->queue[q->rear],item);
	}
}
Boolean IsEmptyQueue(Queue*q)
{
	if(q->front==q->rear)
		return TRUE;
	else return FALSE;
}
Element QueueFront(Queue*q)
{
	if(IsEmptyQueue(q))
		puts("Queue is Empty");
	else
		return q->queue[q->front];
}
Element QueueRear(Queue*q)
{
	if(IsEmptyQueue(q))
		puts("Queue is Empty");
	else
		return q->queue[q->rear];
}

Element Dequeue(Queue*q)
{
	if(IsEmptyQueue(q))
		puts("Queue is Empty");
	else{
		q->front=(q->front+1)%q->size;
		return q->queue[q->front];
	}
}