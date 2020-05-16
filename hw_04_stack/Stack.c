#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>


input(struct stack** sHead, const char str)
{
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s->data = str;
	s->sNext = *sHead;
	*sHead = s;
}

char pop(struct stack** sHead)
{
	if (*sHead == NULL)
		return 0;
	else
	{
		struct stack* s = NULL;
		struct stack* Q = NULL;
		Q = *sHead;
		char result = Q->data;
		*sHead = Q->sNext;
		s = *sHead;
		return result;
	}
}

is_empty(struct stack** sHead)
{
	if (*sHead == NULL)
		return 1;
	else
		return 0;
}
