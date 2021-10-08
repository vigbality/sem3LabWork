#include<stdio.h>
#include"adt.h"
void init(struct arraDT *ptr, int n){
	ptr->n=n;	
}
void input(struct student *ptr){
	printf("\nEnter regNo: ");
	scanf("%d",&ptr->regno);
	printf("Enter name: ");
	scanf("%s%*c",ptr->name);
	printf("Enter M1: ");
	scanf("%d",&ptr->m1);
	printf("Enter M2: ");
	scanf("%d",&ptr->m2);
	printf("Enter M3: ");
	scanf("%d",&ptr->m3);
	ptr->tot = ptr->m1 + ptr->m2 + ptr->m3;
	printf("Enter result(P/F): ");
	scanf("%*c%c%*c",&ptr->result);
}
void insertFront(struct arraDT *l, struct student s){
	for(int i=(l->n)-1; i>=0; i--){
		l->data[i+1] = l->data[i];
	}
	l->data[0] = s;
	(l->n)++;
}

void insertEnd(struct arraDT *l, struct student s){
	l->data[l->n]=s;
	(l->n)++;
}

void insertRegNo(struct arraDT *l, struct student s, int regno){
	for(int i=0; i<l->n; i++){
		if(l->data[i].regno == regno){
			for(int j=(l->n)-1; j>=i+1; j--){
				l->data[j+1] = l->data[j];
			}
			l->data[i+1] = s;
			(l->n)++; break;		
		}	
	}
}

void display(struct arraDT *ptr){
	for(int i=0;i<ptr->n;i++){
		struct student *x = &(ptr->data[i]);	
		printf("\nRegno: %d",x->regno);
		printf("\nname: %s",x->name);
		printf("\nm1: %d",x->m1);
		printf("\nm2: %d",x->m2);
		printf("\nm3: %d",x->m3);
		printf("\ntot: %d",x->tot);
		printf("\nresult: %c",x->result);
		printf("\n\n");
	}
}
