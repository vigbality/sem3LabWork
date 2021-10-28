#include "impl.h"

int main(){
	struct qadt q; init(&q,3);
	int user,done=0,ele;
	while(!done){
		printf("\n\n*****************\nEnter\n1 to INSERT\n2 to DELETE\n3 to DISPLAY\n4 to QUIT\n*****************\ninput: ");
		scanf("%d",&user);
		switch(user){
			case 1:{
				printf("Enter element to be inserted: "); scanf("%d",&ele);
				enqueue(&q,ele);
			};break;
			case 2:{
				ele=dequeue(&q);				
				if(ele==-1) printf("QUEUE IS EMPTY\n");
				else printf("Element deleted: %d\n",ele);
			};break;
			case 3:{
				printf("\n"); display(&q);
			};break;
			case 4:{
				done=1;
			};break;	
		}
	}


	return 0;
}
