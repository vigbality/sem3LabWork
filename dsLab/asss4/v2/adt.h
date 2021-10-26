#include<stdio.h>

struct stack{
	int data[100];
	int top,size;	
};
void init(int size, struct stack *s);
int isFull(struct stack *s);
int isEmpty(struct stack *s);
void push(struct stack *s, int ele);
void pop(struct stack *s);
int top(struct stack *s);
void display(struct stack *s);

