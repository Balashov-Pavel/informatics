#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}node;


typedef struct queue
{
	int data;
	struct node *head;
	struct node *tail;
}queue;

enqueue(struct queue *queue, const int data);
dequeue(struct queue *queue);
is_empty(struct queue queue);
#endif
