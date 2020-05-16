#ifndef STACK_H
#define STACK_H

typedef struct stack {
	char data;
	struct stack* sNext;
}stack;

input(struct stack** sHead, const char str);
char pop(struct stack** sHead);
is_empty(struct stack** sHead);

#endif