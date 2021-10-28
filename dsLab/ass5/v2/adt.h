#include<stdio.h>
struct job{
	int num,time;
};
struct qadt{
	struct job data[100];
	int f, r, size, iter;
};
void enqueue(struct qadt *q, struct job x);
struct job dequeue(struct qadt *q);
void display(struct qadt *q);
int isEmpty(struct qadt *q);
int isFull(struct qadt *q);	
