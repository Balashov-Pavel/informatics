#ifndef STACK_H
#define STACK_H

typedef struct stack {
	int data;
	struct stack* sNext;
}stack;

input(struct stack** sHead, const int num);
int pop(struct stack** sHead);
is_empty(struct stack** sHead);

#endif