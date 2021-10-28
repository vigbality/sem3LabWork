#include "impl.h"

int main(){
	struct qadt q; init(&q,3);
	int user,done=0,id,time;
	struct job ele;	
	while(!done){
		printf("\n\n*****************\nEnter\n1 to INSERT\n2 to DELETE\n3 to DISPLAY\n4 to QUIT\n*****************\ninput: ");
		scanf("%d",&user);
		switch(user){
			case 1:{
				printf("Enter job Num: "); scanf("%d",&id);
				printf("Enter cpu time: "); scanf("%d",&time);
				ele.num=id; ele.time=time;				
				enqueue(&q,ele);
			};break;
			case 2:{
				ele=dequeue(&q);				
				if(ele.num==0) printf("QUEUE IS EMPTY\n");
				else printf("Job deleted: (jobNO: %d,btime: %d)\n",ele.num, ele.time);
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
