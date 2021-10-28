#include "impl.h"

float avgTime(struct qadt *q){
	if(isEmpty(q)) return 0;
	else{
		int avg=0;
		for(int i=q->f+1; i!=q->r; i=(++i)%q->size){
			avg+=(q->data[i].time);
		}
		avg+=(q->data[q->r].time);
		return avg/q->iter;
	}
}


int main(){
	struct qadt q1,q2; init(&q1,10); init(&q2,10);
	int user,done=0,id,time;
	struct job ele;	
	while(!done){
		printf("\n\n*****************\nEnter\n1 to INSERT\n2 to DISPLAY Q1 & Q2\n3 to QUIT\n*****************\ninput: ");
		scanf("%d",&user);
		switch(user){
			case 1:{
				printf("Enter job Num: "); scanf("%d",&id);
				printf("Enter cpu time: "); scanf("%d",&time);
				ele.num=id; ele.time=time;
				if(avgTime(&q1)<avgTime(&q2)) enqueue(&q1,ele);
				else enqueue(&q2,ele);				
				
			};break;
			case 2:{
				printf("\n***** QUEUE 1 ******\n"); display(&q1);
				printf("\n***** QUEUE 2 ******\n"); display(&q2);
			};break;
			case 3:{
				done=1;
			};break;	
		}
	}


	return 0;
}
