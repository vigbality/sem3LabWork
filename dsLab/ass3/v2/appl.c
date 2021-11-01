#include"impl.h"
#include<stdio.h>
#include<stdlib.h>

int isPalindrome(struct listAdt *head){
	struct listAdt *p1=head, *p2=head;
	int yes=1;
	while(p2->next!=NULL) p2=p2->next;
	while(p1!=p2 && p1->next!=p2){
		if(p1->data!=p2->data){
			yes=0;break;
		}
		p1=p1->next; p2=p2->prev;
	}
	return yes;
}


void vowAndCon(struct listAdt *head,struct listAdt **vow, struct listAdt **con){
	struct listAdt *p=head;
	while(p!=NULL){
		char temp=p->data;
		if(temp=='A'||temp=='E'||temp=='I'||temp=='O'||temp=='U'){
			*vow=insertEnd(*vow,temp);
		}
		else{
			*con=insertEnd(*con,temp);
		}
		p=p->next;
	}
}


void swap(struct listAdt *head,int k){
	struct listAdt *p1=head, *p2=head;
	while(p2->next!=NULL) p2=p2->next;
	for(int i=1;i<k-1;i++){
		p1=p1->next; p2=p2->prev;
	}
	char temp;
	temp=p1->next->data;
	p1->next->data=p2->prev->data;
	p2->prev->data=temp;
}


int main(){
	printf("TEST CASE 0\n\n");

	struct listAdt *header0=NULL;
	header0=insertFront(header0,'A');
	header0=insertEnd(header0,'B');
	insertMiddle(header0,'A','E');
	insertMiddle(header0,'A','E');
	display(header0,0);
	printf("count of E: %d\n",searchItem(header0,'E'));
	
	printf("\n\nTEST CASE 1\n\n");

	struct listAdt *header=NULL;	
	header=insertFront(header,'J');
	header=insertFront(header,'U');
	header=insertFront(header,'O');
	header=insertFront(header,'I');
	header=insertFront(header,'P');
	header=insertFront(header,'K');
	header=insertFront(header,'E');
	header=insertFront(header,'C');
	header=insertFront(header,'A');
	display(header,0);

	if(isPalindrome(header)) printf("Palindrome\n");
	else printf("Not a palindrome\n");

	struct listAdt *header2=NULL;	
	header2=insertFront(header2,'A');
	header2=insertFront(header2,'P');
	header2=insertFront(header2,'P');
	header2=insertFront(header2,'A');
	display(header2,0);

	if(isPalindrome(header2)) printf("Palindrome\n");
	else printf("Not a palindrome\n");

	printf("\n\nTEST CASE 2\n\n");
	
	display(header,0);
	struct listAdt *vow=NULL, *con=NULL;
	vowAndCon(header,&vow,&con);
	printf("\n\nVOWELS");
	display(vow,0);
	printf("\nCONSONANTS");
	display(con,0);

	printf("\n\nTEST CASE 3\n\n");

	display(header,0);
	printf("k=2\nafter swapping\n");
	swap(header,2);
	display(header,0);


	return 0;
}
