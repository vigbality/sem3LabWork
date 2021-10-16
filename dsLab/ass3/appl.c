#include"impl.h"
#include<stdio.h>
#include<stdlib.h>

void swap(struct listAdt *head,int k){
	struct listAdt *temp1, *temp2, *ptr=head;
	int i=1;
	while(ptr!=NULL){
		if(i==k){
			temp1=ptr;
		}
		if(ptr->next=NULL){}
	}
}


int main(){
	struct listAdt *header=NULL;
	header=insertFront(header,'F');
	header=insertFront(header,'E');
	header=insertFront(header,'D');
	header=insertFront(header,'C');
	header=insertFront(header,'B');
	header=insertFront(header,'A');
	display(header,0);
}
