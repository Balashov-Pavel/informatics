#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "list_verification.h"

int main()
{
	int menu = -1, n, i, N, num;
	float number;
	struct list* p = NULL;
	printf("Enter n:");
	scanf("%d", &n);
	while (getchar() != '\n');
	for (i = 0; i < n; i++)
	{
		scanf("%f", &number);
		input(&p, number);
	}

	while (menu != 0)
	{
		printf("1 - Output\n");
		printf("2 - Add first\n");
		printf("3 - Add last\n");
		printf("4 - Add N\n");
		printf("5 - Delete first\n");
		printf("6 - Delete last\n");
		printf("7 - Length of list\n");
		printf("8 - Sum of elements\n");
		printf("9 - Maximum of elements\n");
		printf("10 - Minimum of elements\n");
		printf("11 - Average of elements\n");
		printf("12 - Multiples of p\n");
		printf("0 - Exit\n");
		scanf("%d", &menu);
		switch(menu)
		{
		case 0:return 0; break;
		case 1:output(&p); break;
		case 2: {
			while (getchar() != '\n');
			scanf("%f", &number);
			input(&p, number);
		}break;
		case 3: {
			while (getchar() != '\n');
			scanf("%f", &number);
			add_last(&p, number);
		}break;
		case 4: {
			while (getchar() != '\n');
			printf("Enter N:");
			scanf("%d", &N);
			while (getchar() != '\n');
			printf("Enter new symbol:");
			scanf("%f", &number);
			add_N(&p, number, N);
		}break;
		case 5:delete_first(&p); break;
		case 6:delete_last(&p); break;
		case 7:printf("length of list = %.2f\n", length_list(&p)); break;
		case 8:printf("%.2f\n", sum_list(&p)); break;
		case 9:max_list(&p); break;
		case 10:min_list(&p); break;
		case 11:average(&p); break;
		case 12: {
			printf("Enter the number:");
			scanf("%d", &num);
			pcount(&p, num);
		}break;
		default: printf("Error\n");
		}
	}

	while (getchar() != '\n');
	getchar();
}