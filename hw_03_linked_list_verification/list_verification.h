#ifndef _LIST_H
#define _LIST_H

typedef struct list
{
	float value;
	struct list *pNext;
}list;


input(struct list** pHead, const float data);
output(struct list** pHead);
add_last(struct list** pHead, const float data);
add_N(struct list** pHead, const float data, const int N);
delete_first(struct list** pHead);
delete_last(struct list** pHead);
float length_list(struct list** pHead);
float sum_list(struct list** pHead);
float max_list(struct list** pHead);
float min_list(struct list** pHead);
float average(struct list** pHead);
pcount(struct  list** pHead, const int number);
#endif
