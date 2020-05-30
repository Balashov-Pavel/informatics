#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree.h"

int main()
{
	struct node* root = NULL;
	int menu, value, i;
	while (1)
	{
		printf("1 - Add:\n");
		printf("2 - Breadth first search:\n");
		printf("3 - Depth first search:\n");
		printf("4 - Search element:\n");
		printf("0 - Exit\n");
		scanf("%d", &menu);
		switch (menu) {
		case 0: {destruction(root);}return 0;
		case 1: {
			for (i = 0; i < 10; i++)
			{
				if (i % 2 == 0)
				add(&root, i + 5);
				else add(&root, i - 3);
			}
		} break;
		case 2: {bfs(root);} break;
		case 3: {dfs(root); printf("\n");} break;
		case 4: {printf("Enter a search element:"); scanf("%d", &value); search(root, value); } break;
		}
	}

	while (getchar() != '\n');
	getchar();
}