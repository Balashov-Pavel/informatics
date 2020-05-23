#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	int n, i, num, sum_1 = 0, sum_2 = 0;
	printf("Enter n:");
	scanf("%d", &n);

	//Queues and nodes for both windows
	struct queue queue_1;
	queue_1.head = NULL;
	queue_1.tail = NULL;
	struct node *q_1 = NULL;

	struct queue queue_2;
	queue_2.head = NULL;
	queue_2.tail = NULL;
	struct node *q_2 = NULL;

	//Enter first element in the first cashbox
	scanf("%d", &num);
	enqueue(&queue_1, num);
	q_1 = queue_1.head;
	sum_1 += q_1->data;
	//printf("Sum 1 = %d\n", sum_1);

	//Enter second element in the second cashbox
	scanf("%d", &num);
	enqueue(&queue_2, num);
	q_2 = queue_2.head;
	sum_2 += q_2->data;
	//printf("Sum 2 = %d\n", sum_2);

	for (i = 2; i < n; i++)
	{
		if (sum_1 == sum_2)
		{
			scanf("%d", &num);
			enqueue(&queue_1, num);
			q_1 = q_1->next;
			sum_1 += q_1->data;
			//printf("Sum 1 = %d\n", sum_1);

			scanf("%d", &num);
			enqueue(&queue_2, num);
			q_2 = q_2->next;
			sum_2 += q_2->data;
			//printf("Sum 2 = %d\n", sum_2);
			i++;
		}
		else if (sum_1 > sum_2)
		{
			scanf("%d", &num);
			enqueue(&queue_2, num);
			q_2 = q_2->next;
			sum_2 += q_2->data;
			//printf("Sum 2 = %d\n", sum_2);
		}
		else
		{
			scanf("%d", &num);
			enqueue(&queue_1, num);
			q_1 = q_1->next;
			sum_1 += q_1->data;
			//printf("Sum 1 = %d\n", sum_1);
		}
	}

	if (sum_1 > sum_2)
		printf("Result:%d\n", sum_1);
	else
		printf("Result:%d\n", sum_2);
	while (getchar() != '\n');
	getchar();
}