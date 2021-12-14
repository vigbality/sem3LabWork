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
struct arradt{
	struct student data[100];
	int n;
};
void insertFront(struct arradt *ptr, struct student ele);
void insertEnd(struct arradt *ptr, struct student ele);
void insertRegNo(struct arradt *ptr, struct student ele, int regno);
void searchName(struct arradt *ptr, char *name);
void del(struct arradt *ptr, int regno);
void computeResult(struct arradt *ptr);
// struct student *listResult(struct arradt *ptr);
void display(struct arradt *ptr);
void init(struct arradt *ptr);
