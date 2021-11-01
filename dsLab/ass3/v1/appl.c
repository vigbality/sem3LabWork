#include"impl.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
	struct listAdt *header=NULL;
	header=insertFront(header,'F');
	header=insertFront(header,'E');
	header=insertFront(header,'D');
	header=insertFront(header,'C');
	header=insertFront(header,'B');
	header=insertFront(header,'A');
	display(header,0);
	insertMiddle(header,'E','+');
	insertMiddle(header,'F','G');
	display(header,0);
	deleteItem(header,'+');
	display(header,0);
	header=insertEnd(header,'C');
	display(header,0);
	printf("count of C: %d\n",searchItem(header,'C'));
	printf("count of Z: %d\n",searchItem(header,'Z'));
}
