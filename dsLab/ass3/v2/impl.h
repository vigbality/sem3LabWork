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
		head->prev=temp;
		temp->prev=head;
	}
	 head=temp;
	 return head;
}


struct listAdt *insertEnd(struct listAdt *head, char c){
	struct listAdt *p=head;
	struct listAdt *temp= (struct listAdt*) malloc(sizeof(struct listAdt));
	temp->data=c;temp->next=NULL;
	if(p==NULL){
		temp->prev=head;
		head=temp;
	}
	else{
		while(p->next!=NULL) p=p->next;
		temp->prev=p;
		p->next=temp;
	}
	return head;
}


void insertMiddle(struct listAdt *head, char c, char d){
	struct listAdt *p=head;
	struct listAdt *temp= (struct listAdt*) malloc(sizeof(struct listAdt));
	temp->data=d;
	while(p->next!=NULL && p->data!=c) p=p->next;
	if(p->next==NULL&& p->data!=c){
		printf("ELEMENT NOT FOUND\n");
	}
	else if(p->next==NULL&& p->data==c){
		temp->next=NULL;
		temp->prev=p;
		p->next=temp;
	}
	else{
		temp->next=p->next;
		temp->prev=p;
		p->next->prev=temp;
		p->next=temp;

	}
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

void deleteItem(struct listAdt *head, char c){
	struct listAdt *p=head;
	while(p->next!=NULL && p->data!=c) p=p->next;
	if(p->next==NULL&& p->data!=c){
		printf("ELEMENT NOT FOUND\n");
	}
	else{
		p->prev->next=p->next;
		free(p);p=NULL;
	}
}

int searchItem(struct listAdt *head, char c){
	struct listAdt *p=head;
	int count=0;
	while(p!=NULL){
		if(p->data==c) count++;
		p=p->next;
	}
	return count;
}