#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

processing()
{
	int sum_1 = 0, sum_2 = 0, value;

	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;

	scanf("%d", &value);
	if (value == -1)
	{
		printf("Why are you here?");
		return 0;
	}
	else 
		while (value != -1)
			{
				enqueue(&queue, value);
				scanf("%d", &value);
			}

	struct node *q = queue.head;

	while (q)
	{
		 if (sum_1 <= sum_2)
		{
			 sum_1 += q->data;
			 q = q->next;
			 dequeue(&queue);
		}
		else
		{
			sum_2 += q->data;
			q = q->next;
			dequeue(&queue);
		}
	}
	if (sum_1 > sum_2)
	{
		printf("Result:%d\n", sum_1);
		return 0;
	}
	else
	{
		printf("Result:%d\n", sum_2);
		return 0;
	}
}

int main()
{
	processing();

	while (getchar() != '\n');
	getchar();
}