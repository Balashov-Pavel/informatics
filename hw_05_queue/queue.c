#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

enqueue(struct queue *queue, const float data)
{
	struct node *q = (struct node *)malloc(sizeof(struct node));

	q->data = data;
	q->prev = queue->tail;
	q->next = NULL;

	if (queue->tail == NULL)
		queue->head = q;
	else
		queue->tail->next = q;
	queue->tail = q;
}

dequeue(struct queue *queue)
{
	struct node *q = queue->head;
	queue->head = queue->head->next;
	free(q);
	if (queue->head == NULL)
		queue->tail = NULL;
	else
		queue->head->prev = NULL;
}

is_empty(struct queue queue)
{
	if (queue.head == NULL)
		return 0;
	else return 1;
}

