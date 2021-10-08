#include<stdio.h>
struct student{
	long int regno;
	char name[20];
	int m1;
	int m2;
	int m3;
	int tot;
	char result;	
}
struct arradt{
	struct student data[100];
	int n;
};
void insert(struct arradt *ptr);
void display(struct arradt *ptr);
void init(struct student *ptr);
