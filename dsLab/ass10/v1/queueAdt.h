#include<stdio.h>
struct qadt{
	int data[100], f, r, size, iter;
};

void enqueue(struct qadt *q, int x);
int dequeue(struct qadt *q);
void displayQ(struct qadt *q);
int isEmptyQ(struct qadt *q);
int isFullQ(struct qadt *q);	
