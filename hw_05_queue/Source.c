#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

super_average(float *array, const int n, const int k)
{
	int i;
	float sum = 0;
	int length = 0;

	struct queue queue;
	queue.head = NULL;
	queue.tail = NULL;

	for (i = 0; i < k; i++)
	{
		enqueue(&queue, array[i]);
		sum += array[i];
		length++;
		printf("%.2f ", sum / length);
	}
	
	for (i = k; i < n; i++)
	{
		dequeue(&queue);
		sum -= array[i - k];
		enqueue(&queue, array[i]);
		sum += array[i];
		printf("%.2f ", sum / length);
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