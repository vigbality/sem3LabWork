#include<stdio.h>

struct listAdt{
	char data;
	struct listAdt *prev, *next;
};
struct listAdt *insertFront(struct listAdt *head, char c);
struct listAdt *insertEnd(struct listAdt *head, char c);
void insertMiddle(struct listAdt *head, char c, char d);
void display(struct listAdt *head,int rev);
void deleteItem(struct listAdt *head, char c);
int searchItem(struct listAdt *head, char c);

