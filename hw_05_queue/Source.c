#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

float sum(struct queue queue)
{
	float sum = 0;

	struct node *q = queue.head;

	while (q)
	{
		sum += q->data;
		q = q->next;
	}

	return sum;
}

super_average(float *array, const int n, const int k)
{
	int i;
	//Инициализация очереди
	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;

	/*Добавление в очередь первых k элементов.
	*/
	for (i = 0; i < k; i++)
	{
		//Добавление нового элемента в очередь
		enqueue(&queue, array[i]);
		printf("%.2f ", sum(queue) / length(queue));
	}
	
	for (i = k; i < n; i++)
	{
		//Удаление первого элемента
		dequeue(&queue);
		//Добавление нового элемента
		enqueue(&queue, array[i]);
		printf("%.2f ", sum(queue) / length(queue));
	}
	printf("\n");
}

int main()
{
	int n, k, i;
	printf("n, k:");
	scanf("%d %d", &n, &k);

	float *arr = (float *)malloc(n * sizeof(float));
	for (i = 0; i < n; i++)
		scanf("%f", &arr[i]);

	super_average(arr, n, k);

	while (getchar() != '\n');
	getchar();
}