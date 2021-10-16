#include<stdio.h>

struct listAdt{
	char data;
	struct listAdt *prev, *next;
};
struct listAdt *insertFront(struct listAdt *head, char c);
void display(struct listAdt *head,int rev);

