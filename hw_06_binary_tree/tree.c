#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

add(struct node** root, int new_value)
{
	if (*root == NULL)
	{
		*root = (struct node*)malloc(sizeof(struct node));
		(*root)->data = new_value;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else 
	{
		if (new_value > (*root)->data)
			add(&(*root)->right, new_value);
		else
			add(&(*root)->left, new_value);
	}
}

dfs(struct node* root)
{
	if (root == NULL) 
	{
		printf("Tree is empty!");  
		return 0;
	}

	printf("%d ", root->data);
	if (root->left != NULL)
		dfs(root->left);
	if (root->right != NULL)
		dfs(root->right);
	return 0;
}

enqueue(struct queue** head, struct queue** tail, struct node* value)
{
	struct queue* q = (struct queue*)malloc(sizeof(struct queue));
	q->next = NULL;
	q->tree = value;
	if ((*head == NULL) && (*tail == NULL))
		*head = q;
	else 
		(*tail)->next = q;
	*tail = q;
}

struct node* dequeue(struct queue** head, struct queue** tail)
{
	struct node* res;
	res = (*head)->tree;
	struct queue* old;
	old = *head;
	*head = (*head)->next;
	if (*head == NULL)
		*tail = NULL;
	free(old);
	return res;
}

bfs(struct node* root)
{
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);
	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;

		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL) {
				printf("Tree is empty!\n");  return 0;
			}
			if (value->left)
				enqueue(&new_head, &new_tail, value->left);
			if (value->right)
				enqueue(&new_head, &new_tail, value->right);
			printf("%d ", value->data);
		}
		printf("\n");
		head = new_head;
		tail = new_tail;
	}
	return 0;
}

search(struct node* root, const int num)
{
	int k = 0;
	struct queue* head;
	struct queue* tail;
	head = NULL;
	tail = NULL;
	enqueue(&head, &tail, root);

	while (head != NULL)
	{
		struct queue* new_head;
		struct queue* new_tail;
		new_head = NULL;
		new_tail = NULL;

		while (head != NULL)
		{
			struct node* value;
			value = dequeue(&head, &tail);
			if (value == NULL)
			{
				printf("Tree is empty!\n");  
				return 0;
			}

		if (value->data == num)
		{	
			printf("Level = %d\n", k);
			return 0;
		}

		if (value->left)
		enqueue(&new_head, &new_tail, value->left);
		if (value->right)
		enqueue(&new_head, &new_tail, value->right);
		}
	k++;
	head = new_head;
	tail = new_tail;
	}
	printf("There is no needed element\n");
	return 0;
}

void destruction(struct node* root)
{
	if (root)
	{
		destruction(root->left);
		destruction(root->right);
		free(root);
	}
}