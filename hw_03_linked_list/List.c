#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

input(struct list** pHead, const char data)
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
			printf("%c", p->value);
			p = p->pNext;
		}
		printf("\n");
	}
}


add_last(struct list** pHead, const char data)
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

add_N(struct list** pHead, const char data, const int N)
{
	int i;
	struct list* p = (struct list*)malloc(sizeof(struct list));
	struct list* G = (struct list*)malloc(sizeof(struct list));
	G->value = data;
	p = *pHead;
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
	if (*pHead == NULL)
	{
		printf("Error\n");
	}
	else 
	{
		struct list* p = NULL;
		struct list* F = NULL;
		F = *pHead;
		p = *pHead;
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
