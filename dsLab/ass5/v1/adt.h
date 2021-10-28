#include<stdio.h>
struct qadt{
	int data[100], f, r, size, iter;
};
void enqueue(struct qadt *q, int x);
int dequeue(struct qadt *q);
void display(struct qadt *q);
int isEmpty(struct qadt *q);
int isFull(struct qadt *q);	
