#include<stdio.h>
#include"impl.h"

int main(){
	struct arradt data;
	printf("Please enter the array length: ");
	scanf("%d",&data.n);
	insert(&data);
	printf("\nafter calling display func...\n\n");
	display(&data);
	return 0;
}
