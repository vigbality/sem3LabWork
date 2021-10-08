#include<stdio.h>
#include"impl.h"

int main(){
	struct arraDT data;
	printf("Enter n value to init: ");
	int n; scanf("%d",&n);
	init(&data,n);
	struct student temp;
	for(int x=0;x<n;x++){
		input(&temp);
		data.data[x]=temp;
	}
	int user;
	int done = 0;
	while(done==0){
		printf("\n\n---------------------\nEnter\n1 to insertFront\n2 to insertEnd\n3 to insertRegNO\n4 to display\n5 to quit\n------------------------\ninput: ");
		scanf("%d",&user);
		switch(user){
			case 1:{
				input(&temp);
				insertFront(&data,temp);	
			};break;
			case 2:{
				input(&temp);
				insertEnd(&data,temp);	
			};break;
			case 3:{
				input(&temp);
				int regno; printf("Enter regno: ");
				scanf("%d",&regno); printf("\n");
				insertRegNo(&data,temp,regno);	
			};break;
			case 4:{
				display(&data);
			};break;
			case 5:{
				done = 1;
			};break;	
		};
	}
	return 0;
}
