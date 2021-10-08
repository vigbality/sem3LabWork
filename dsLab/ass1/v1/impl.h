#include<stdio.h>
#include"adt.h"

void insert(struct arradt *ptr){
	for(int i=0;i<ptr->n;i++){
		printf("Enter %dth value: ",i+1);
		scanf("%d",&ptr->a[i]);
		printf("\n");
	}
}

void display(struct arradt *ptr){
	for(int i=0;i<ptr->n;i++){
		printf("%d ",ptr->a[i]);	
	}
	printf("\n");
}
