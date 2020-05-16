#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>


int main()
{
	char str[100];
	int  i;

	while (1)
	{
		struct stack* s = NULL;
		i = 0;
		printf("Enter the expression:");
		gets_s(str, 100);
		while (str[i] != '\0')
		{
			switch (str[i]) {
			case '0': input(&s, 0);break;
			case '1': input(&s, 1);break;
			case '2': input(&s, 2);break;
			case '3': input(&s, 3);break;
			case '4': input(&s, 4);break;
			case '5': input(&s, 5);break;
			case '6': input(&s, 6);break;
			case '7': input(&s, 7);break;
			case '8': input(&s, 8);break;
			case '9': input(&s, 9);break;
			case '+': input(&s, pop(&s) + pop(&s));break;
			case '-': input(&s, - pop(&s) + pop(&s));break;
			case '*': input(&s, pop(&s) * pop(&s));break;
			}
			i++;
		}
		printf("result = %d\n", s->data);
	}

	while (getchar() != '\n');
}