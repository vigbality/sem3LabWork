#include<stdio.h>
#include"adt.h"
void init(struct student *ptr){
	printf("\nEnter regNo: ");
	scanf("%ld",&ptr->regno);
	printf("\nEnter name: ");
	scanf("%s%*c",ptr->name);
	printf("\nEnter M1: ");
	scanf("%d",&ptr->m1);
	printf("\nEnter M2: ");
	scanf("%d",&ptr->m3);
	printf("\nEnter M3: ");
	scanf("%d",&ptr->m3);
	ptr->tot = ptr->m1 + ptr->m2 + ptr->m3;
	printf("\nEnter result(P/F): ");
	scanf("%c%*c",&ptr->result);
}
void insert(struct arradt *ptr){
	init(ptr + ptr->n +1);
	(ptr->n)++;
	
}

void display(struct arradt *ptr){
	for(int i=0;i<ptr->n;i++){
		printf("\nRegno: %ld",(ptr+i)->regno);
		printf("\nname: %s",(ptr+i)->name);
		printf("\nm1: %d",(ptr+i)->m1);
		printf("\nm2: %d",(ptr+i)->m2);
		printf("\nm3: %d",(ptr+i)->m3);
		printf("\ntot: %d",(ptr+i)->tot);
		printf("\nresult: %c",(ptr+i)->result);
		printf("\n\n");
	}
}
