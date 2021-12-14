#include"stackAdt.h"
void initS(int size, struct stack *s){
	s->size=size;
	s->top=-1;
}

int isFullS(struct stack *s){
	if(s->top<s->size) return 0;
	else return 1;
}

int isEmptyS(struct stack *s){
	if(s->top==-1) return 1;
	else return 0;
}

void push(struct stack *s, int ele){
	s->top++;
	if(isFullS(s)){
		printf("Stack is Full\n");
		s->top--;
	}
	else s->data[s->top]=ele;
}

void pop(struct stack *s){
	if(isEmptyS(s)) printf("Stack is Empty\n");
	else s->top--;
}

int top(struct stack *s){
	if(isEmptyS(s)) printf("Stack is Empty\n");
	else return s->data[s->top];
}

void displayS(struct stack *s){
	for(int i=0;i<=s->top;i++){
		printf("%d ",s->data[i]);
	}
	printf("\n\n");
}
