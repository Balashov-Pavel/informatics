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

check(const char* str)
{
	struct stack* s = NULL;
	struct stack* sHead = NULL;
	int len = strlen(str), i;

	if (str[0] == '(')
		input(&s, str[0]);
	else if (str[0] == ')')
		return 0;

	if (str[0] == '[')
		input(&s, str[0]);
	else if (str[0] == ']')
		return 0;

	if (str[0] == '{')
		input(&s, str[0]);
	else if (str[0] == '}')
		return 0;

	for (i = 1; i < len; i++)
	{
		if (str[i] == '(')
			input(&s, str[i]);
		else if (str[i] == ')')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->data == '(')
					pop(&s);
				else return 0;
			}
		}

		if (str[i] == '[')
			input(&s, str[i]);
		else if (str[i] == ']')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->data == '[')
					pop(&s);
				else return 0;
			}
		}

		if (str[i] == '{')
			input(&s, str[i]);
		else if (str[i] == '}')
		{
			if (is_empty(&s))
				return 0;
			else
			{
				if (s->data == '{')
					pop(&s);
				else return 0;
			}
		}
	}

	if (is_empty(&s))
		return 1;
	else return 0;
}