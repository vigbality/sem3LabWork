#include"impl.h"
#include<stdlib.h>

struct student *newStudent(){
    struct student *temp=(struct student*)malloc(sizeof(struct student));
    printf("\nEnter regNo: ");
    scanf("%d%*c",&temp->regno);
	printf("\nEnter name: ");
	scanf("%s%*c",temp->name);
	printf("\nEnter M1: ");
	scanf("%d%*c",&temp->m1);
	printf("\nEnter M2: ");
	scanf("%d%*c",&temp->m2);
	printf("\nEnter M3: ");
	scanf("%d%*c",&temp->m3);
	temp->tot = temp->m1 + temp->m2 + temp->m3;
	return temp;
}


void main(){
    int done=0,chc,reg;
	struct arradt list;
	char *name;
	init(&list);
	while(!done){
		printf("\n\nEnter\n1 to insertFront\n2 to insertBack\n3 to insertMiddle\n4 to searchname\n5 to delete\n6 to computer result\n7 to display\n8 to exit\nYour choice: ");
		scanf("%d",&chc);
		switch(chc){
			case 1:{
				insertFront(&list,*newStudent());
			};break;
			case 2:{
				insertEnd(&list,*newStudent());
			};break;
			case 3:{
				printf("\nEnter regno: ");
				scanf("%d",&reg);
				insertRegNo(&list,*newStudent(),reg);
			};break;
			case 4:{
				printf("\nENter name: ");
				scanf("%s",name);
				searchName(&list,name);
			};break;
			case 5:{
				printf("\nEnter regno: ");
				scanf("%d",&reg);
				del(&list,reg);
			};break;
			case 6:{
				computeResult(&list);
			};break;
			case 7:{
				display(&list);
			};break;
			case 8:{
				done=1;
			};break;
		}
	}
}



	
