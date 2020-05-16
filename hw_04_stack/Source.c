#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack.h"
#include <string.h>

int main()
{
	char str[100];
	int menu = -1, result;

	while (1)
	{
		printf("Enter the string:");
		gets_s(str, 100);
		result = check(str);
		if (result)
			puts("OK!");
		else puts("NOT OK!");
	}

	while (getchar() != '\n');
}