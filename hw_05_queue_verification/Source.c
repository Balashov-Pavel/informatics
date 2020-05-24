#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

function(int *arr, const int n)
{
	int i, sum_1 = 0, sum_2 = 0;

	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;

	for (i = 0; i < n; i++)
		enqueue(&queue, arr[i]);

	struct node *q = queue.head;

	for (i = 0; i < n; i++)
	{
		if (sum_1 == sum_2)
		{
			sum_1 += q->data;
			q = q->next;
			dequeue(&queue);

			sum_2 += q->data;
			q = q->next;
			dequeue(&queue);
			i++;
		}
		else if (sum_1 > sum_2)
		{
			sum_2 += q->data;
			q = q->next;
			dequeue(&queue);
		}
		else
		{
			sum_1 += q->data;
			q = q->next;
			dequeue(&queue);
		}
	}
	if (sum_1 > sum_2)
		printf("Result:%d\n", sum_1);
	else
		printf("Result:%d\n", sum_2);
}

int main()
{
	int n, i;
	printf("Enter n:");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	function(arr, n);

	while (getchar() != '\n');
	getchar();
}