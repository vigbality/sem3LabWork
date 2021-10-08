#include<stdio.h>
struct student{
	int regno;
	char name[20];
	int m1;
	int m2;
	int m3;
	int tot;
	char result;	
};
struct arraDT{
	struct student data[100];
	int n;
};
void insertFront(struct arraDT *l, struct student s);
void insertEnd(struct arraDT *l, struct student s);
void insertRegNo(struct arraDT *l, struct student s, int regno);
void display(struct arraDT *ptr);
void input(struct student *ptr);
void init(struct arraDT *ptr, int n);
