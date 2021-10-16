#include"adt.h"
#include<stdio.h>
#include<stdlib.h>
struct listAdt *insertFront(struct listAdt *head, char c){
	struct listAdt *temp= (struct listAdt*) malloc(sizeof(struct listAdt));
	temp->data=c;
	if(head==NULL){
		temp->next=NULL;
		temp->prev=head;
	}
	else{
		temp->next=head;
		temp->prev=head->prev;
	}
	head=temp;
	return head; 
}

void display(struct listAdt *head,int rev){
	printf("\n");
	struct listAdt *ptr=head;
	if(rev==0){
		while(ptr!=NULL){
			printf("%c ",ptr->data);
			ptr=ptr->next;
		}
		
	}
	else{
		while(ptr->next!=NULL) ptr=ptr->next;
		while(ptr!=head){
			printf("%c ",ptr->data);
			ptr=ptr->prev;
		}
		printf("%c ",ptr->data);
	}
	printf("\n");
}
