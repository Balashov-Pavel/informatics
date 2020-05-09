#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list_verification.h"

input(struct list** pHead, const float data)
{
	struct list* p = (struct list*)malloc(sizeof(struct list));
	p->value = data;
	p->pNext = *pHead;
	*pHead = p;
}

output(struct list** pHead)
{
	if (*pHead == NULL)
	{
		printf("HERE IS EMPTY\n");
	}
	else
	{
		struct list* p = *pHead;
		while (p != NULL)
		{
			printf("%.2f ", p->value);
			p = p->pNext;
		}
		printf("\n");
	}
}


add_last(struct list** pHead, const float data)
{
	struct list* p = (struct list*)malloc(sizeof(struct list));
	p->value = data;
	p->pNext = NULL;
	struct list* T = *pHead;
	if (T != NULL)
	{
		while (T->pNext)
			T = T->pNext;
	}
	else  *pHead = p;
	T->pNext = p;
}

add_N(struct list** pHead, const float data, const int N)
{
	int i;
	struct list* p = *pHead;
	struct list* G = (struct list*)malloc(sizeof(struct list));
	G->value = data;
	for (i = 0; i < N - 2; i++)
		p = p->pNext;
	G->pNext = p->pNext;
	p->pNext = G;
}

delete_first(struct list** pHead)
{
	if (*pHead == NULL)
	{
		printf("Error\n");
	}
	else
	{
		struct list* p = NULL;
		struct list *Q = NULL;
		Q = *pHead;
		*pHead = Q->pNext;
		free(Q);
		p = *pHead;
	}
}

delete_last(struct list** pHead)
{
	struct list* p = NULL;
	struct list* F = NULL;
	F = *pHead;
	p = *pHead;
	if (*pHead == NULL)
	{
		printf("Error\n");
	}
	else if (p->pNext == NULL)
	{
		struct list *Q = NULL;
		Q = *pHead;
		*pHead = Q->pNext;
		free(Q);
		p = *pHead;
	}
	else
	{
		F = F->pNext;
		while (F->pNext != NULL)
		{
			F = F->pNext;
			p = p->pNext;
		}
		p->pNext = NULL;
		free(F);
		p = *pHead;
	}
}


float length_list(struct list** pHead)
{
	float length = 0.0;
	struct list* p = *pHead;
	while (p)
	{
		p = p->pNext;
		length++;
	}
	return length;
}


float sum_list(struct list** pHead)
{
	if (*pHead == NULL)
	{
		printf("HERE IS EMPTY\n");
		return 0;
	}
	else 
	{
		float sum = 0.0;
		struct list* p = *pHead;
		while (p)
		{
			sum += p->value;
			p = p->pNext;
		}
		return sum;
	}
}


float max_list(struct list** pHead)
{
	if (*pHead == NULL)
	{
		printf("HERE IS EMPTY\n");
		return 0;
	}
	else 
	{
		struct list* p = *pHead;
		float max = p->value;
		p = p->pNext;
		while (p)
		{
			if (p->value > max)
				max = p->value;
			p = p->pNext;
		}
		printf("maximum of elements = %.2f\n", max);
		return 0;
	}
}


float min_list(struct list** pHead)
{
	if (*pHead == NULL)
	{
		printf("HERE IS EMPTY\n");
		return 0;
	}
	else
	{
		struct list* p = *pHead;
		float min = p->value;
		p = p->pNext;
		while (p)
		{
			if (p->value < min)
				min = p->value;
			p = p->pNext;
		}
		printf("minimum of elements = %.2f\n", min);
		return 0;
	}
}


float average(struct list** pHead)
{
	if (*pHead == NULL)
	{
		printf("HERE IS EMPTY\n");
		return 0;
	}
	else 
	{
		float avg;
		struct list* p = *pHead;
		avg = sum_list(&p) / length_list(&p);
		printf("average of elements = %.2f\n", avg);
		return 0;
	}
}

//Enter 1-3 numbers after point for success
pcount(struct  list** pHead, const int number)
{
	if (*pHead == NULL)
	{
		printf("HERE IS EMPTY\n");
		return 0;
	}
	else
	{
		int count = 0;
		int value;
		struct list* p = *pHead;
		while (p)
		{
			value = (int)(p->value * 1000);
			if (value % (number*1000) == 0)
				count++;
			p = p->pNext;
		}
		printf("Multiples of p = %d\n", count);
		return 0;
	}
}
