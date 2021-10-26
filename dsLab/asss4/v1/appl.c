#include "impl.h"

void main(){
	struct stack s;
	init(3,&s);
	int exit=0,in;
	while(!exit){
		printf("\n******************\nEnter\n1 to PUSH\n2 to POP\n3 to getTOP\n4 to DISPLAY\n5 to QUIT\n******************\n");
		scanf("%d",&in);
		switch(in){
			case 1:{
				int ele;printf("\nEnter element to push: \n");
				scanf("%d",&ele);
				push(&s,ele);
			}break;
			case 2: pop(&s);break;
			case 3:{
				printf("\nElement at TOP: %d\n",top(&s));
			}break;
			case 4: display(&s);break;
			case 5: exit=1;break;
		}
	}
	
}
