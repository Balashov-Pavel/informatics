#ifndef _TREE_H
#define _TREE_H

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct queue
{
	struct queue* next;
	struct node* tree;
}queue;

add(struct node** root, int new_value);
dfs(struct node* node);
enqueue(struct queue** head, struct queue** tail, struct node* value);
struct node* dequeue(struct queue** head, struct queue** tail);
bfs(struct node* root);
search(struct node* root, const int num);
void destruction(struct node* root);
#endif 