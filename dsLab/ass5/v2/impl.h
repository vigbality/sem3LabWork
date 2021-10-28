#include "adt.h"

void init(struct qadt *q, int s){
	q->size=s;
	q->f=q->r=-1;
	q->iter=0;
}

int isEmpty(struct qadt *q){
	if(q->iter==0) return 1;
	else return 0;
}
int isFull(struct qadt *q){
	if(q->iter<q->size) return 0;
	else return 1;
}


void enqueue(struct qadt *q, struct job x){
	if(isFull(q)) printf("QUEUE IS FULL\n");
	else{
		q->iter++;
		q->r=(++q->r)%q->size;
		q->data[q->r]=x;
	}
}

struct job dequeue(struct qadt *q){	
	if(isEmpty(q)){
		static struct job nullJob;
		return nullJob;
	}
	else{
		q->iter--;
		q->f=(++q->f)%q->size;
		return q->data[q->f];
	}
}
void display(struct qadt *q){
	if(isEmpty(q)) printf("QUEUE IS EMPTY");
	else{
		for(int i=q->f+1; i!=q->r; i=(++i)%q->size){
			printf("(jobNO: %d,btime: %d) ",q->data[i].num, q->data[i].time);
		}
		printf("(jobNO: %d,btime: %d)\n",q->data[q->r].num, q->data[q->r].time);
	}
}

