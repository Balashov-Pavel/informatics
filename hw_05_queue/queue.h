#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct node
{
	float data;
	struct node *next;
	struct node *prev;
}node;

/*��������� queue ����� ��������� �� head � tail
��� ���� head � tail ����� �������� ����(node).
*/
typedef struct queue
{
	float data;
	struct node *head;
	struct node *tail;
}queue;

enqueue(struct queue *queue, const float data);
dequeue(struct queue *queue);
int length(struct queue queue);
is_empty(struct queue queue);
#endif 