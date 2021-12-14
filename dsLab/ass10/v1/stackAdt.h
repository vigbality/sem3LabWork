#include<stdio.h>

struct stack{
	int data[100];
	int top,size;	
};

int isFullS(struct stack *s);
int isEmptyS(struct stack *s);
void push(struct stack *s, int ele);
void pop(struct stack *s);
int top(struct stack *s);
void displayS(struct stack *s);

